#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add.h"
#include "delete.h"
#include "addcategories.h"
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonAddCategories, &QPushButton::clicked, this, [=]() {
        AddCategories dlg(this, db);
        dlg.exec();
        loadCategories();
    });
    connect(ui->pushButtonAddProduct, &QPushButton::clicked, this, &MainWindow::on_pushButtonAddProduct_clicked);
    connect(ui->pushButtonDeleteProduct, &QPushButton::clicked, this, &MainWindow::on_pushButtonDeleteProduct_clicked);

    connectToDatabase();
    loadCategories();

    ui->buttonBack->setText("←");
    ui->buttonBack->setToolTip("Повернутись назад");
    ui->buttonBack->setVisible(false);
    connect(ui->buttonBack, &QToolButton::clicked, this, &MainWindow::loadCategories);
}

MainWindow::~MainWindow()
{
    if (db.isOpen()) db.close();
    delete ui;
}

void MainWindow::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={PostgreSQL ANSI(x64)};"
                       "Server=localhost;"
                       "Port=5432;"
                       "Database=Elc_Store;"
                       "Uid=postgres;"
                       "Pwd=1234567890123;"
                       "SSLmode=disable;");
    if (!db.open())
        QMessageBox::critical(this, "Помилка", "Не вдалося підключитися до бази даних:\n" + db.lastError().text());
}

void MainWindow::loadCategories()
{
    if (!db.isOpen()) return;
    currentCategory.clear();
    ui->buttonBack->setVisible(false);

    auto *model = new QSqlQueryModel(this);
    model->setQuery(R"(
        SELECT
            category_name AS "Категорія товарів"
        FROM categories
        ORDER BY category_id ASC
    )", db);

    if (model->lastError().isValid()) {
        QMessageBox::warning(this, "Помилка",
                             "Не вдалося завантажити категорії:\n" + model->lastError().text());
        return;
    }

    ui->tableViewProducts->setModel(model);
    ui->tableViewProducts->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewProducts->verticalHeader()->setVisible(false);
    ui->tableViewProducts->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewProducts->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewProducts->setAlternatingRowColors(true);
    ui->tableViewProducts->setShowGrid(true);

    connect(ui->tableViewProducts->selectionModel(),
            &QItemSelectionModel::currentRowChanged,
            this, &MainWindow::onCategorySelected);
}

void MainWindow::onCategorySelected(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QString categoryName = ui->tableViewProducts->model()
                               ->data(ui->tableViewProducts->model()->index(index.row(), 0))
                               .toString().trimmed();

    if (!categoryName.isEmpty())
        loadProducts(categoryName);
}

void MainWindow::loadProducts(QString category)
{
    if (!db.isOpen())
        return;

    currentCategory = category;
    ui->buttonBack->setVisible(true);

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString query = QString(R"(
        SELECT p.product_id AS "ID",
               p.brand       AS "Бренд",
               p.model       AS "Модель",
               p.release_year AS "Рік випуску",
               p.price        AS "Ціна",
               p.stock        AS "Кількість"
        FROM products p
        JOIN categories c ON p.category_id = c.category_id
        WHERE LOWER(c.category_name) = LOWER('%1')
        ORDER BY p.product_id DESC
    )").arg(category);

    model->setQuery(query, db);

    if (model->lastError().isValid()) {
        QMessageBox::warning(this, "Помилка",
                             "Не вдалося завантажити товари:\n" + model->lastError().text());
        return;
    }

    ui->tableViewProducts->setModel(model);
    ui->tableViewProducts->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewProducts->setAlternatingRowColors(true);
    ui->tableViewProducts->setSortingEnabled(true);

    QHeaderView *header = ui->tableViewProducts->horizontalHeader();
    connect(header, &QHeaderView::sectionClicked, this, [=](int logicalIndex) {
        QString columnName;
        if (logicalIndex == 4) columnName = "p.price";
        else if (logicalIndex == 5) columnName = "p.stock";
        else return;

        static bool ascending = true;
        QString order = ascending ? "ASC" : "DESC";
        ascending = !ascending;

        QString sortQuery = QString(R"(
            SELECT p.product_id AS "ID",
                   p.brand       AS "Бренд",
                   p.model       AS "Модель",
                   p.release_year AS "Рік випуску",
                   p.price        AS "Ціна",
                   p.stock        AS "Кількість"
            FROM products p
            JOIN categories c ON p.category_id = c.category_id
            WHERE LOWER(c.category_name) = LOWER('%1')
            ORDER BY %2 %3
        )").arg(currentCategory, columnName, order);

        model->setQuery(sortQuery, db);
    });
}
void MainWindow::on_pushButtonAddProduct_clicked()
{
    static bool isOpen = false;
    if (isOpen) return;
    isOpen = true;

    auto *dlg = new Add(this, db);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    connect(dlg, &QDialog::finished, this, [&]() {
        isOpen = false;
        loadCategories();
    });
    dlg->show();
}

void MainWindow::on_pushButtonDeleteProduct_clicked()
{
    static bool isOpen = false;
    if (isOpen) return;
    isOpen = true;

    auto *dlg = new Delete(this, db);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    connect(dlg, &QDialog::finished, this, [&]() {
        isOpen = false;
        loadCategories();
    });
    dlg->show();
}
