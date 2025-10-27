#include "delete.h"
#include "ui_delete.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QAbstractItemView>

Delete::Delete(QWidget *parent, QSqlDatabase database)
    : QDialog(parent)
    , ui(new Ui::Delete)
    , db(database)
{
    ui->setupUi(this);
    setWindowTitle("Видалення товару");
    ui->comboBoxCategory->clear();
    QSqlQuery query(db);
    if (query.exec("SELECT category_id, category_name FROM categories ORDER BY category_id ASC")) {
        while (query.next()) {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            ui->comboBoxCategory->addItem(name, id);
        }
    } else {
        qDebug() << "Помилка при завантаженні категорій:" << query.lastError().text();
    }

    connect(ui->comboBoxCategory, &QComboBox::currentIndexChanged,
            this, &Delete::onCategoryChanged);
    connect(ui->pushButtonDelete, &QPushButton::clicked,
            this, &Delete::onDeleteClicked);
    connect(ui->pushButtonClose, &QPushButton::clicked,
            this, &QDialog::accept);
    onCategoryChanged(0);
}

Delete::~Delete()
{
    delete ui;
}

void Delete::onCategoryChanged(int index)
{
    Q_UNUSED(index);

    if (!db.isOpen()) {
        QMessageBox::warning(this, "Помилка", "База даних не підключена!");
        return;
    }
    int categoryId = ui->comboBoxCategory->currentData().toInt();
    loadProductIDs(categoryId);
}

void Delete::loadProductIDs(int categoryId)
{
    ui->comboBoxProductID->clear();

    QSqlQuery query(db);
    query.prepare(R"(
        SELECT product_id, brand, model
        FROM products
        WHERE category_id = ?
        ORDER BY product_id ASC
    )");
    query.addBindValue(categoryId);

    if (!query.exec()) {
        QMessageBox::warning(this, "Помилка",
                             "Не вдалося отримати список товарів:\n" + query.lastError().text());
        return;
    }

    while (query.next()) {
        int id = query.value(0).toInt();
        QString brand = query.value(1).toString();
        QString model = query.value(2).toString();
        QString displayText = QString("%1 — %2 %3").arg(id).arg(brand).arg(model);
        ui->comboBoxProductID->addItem(displayText, id);
    }

    ui->comboBoxProductID->view()->setTextElideMode(Qt::ElideNone);
    ui->comboBoxProductID->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    ui->comboBoxProductID->view()->setMinimumWidth(350);
}
void Delete::onDeleteClicked()
{
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Помилка", "База даних не підключена!");
        return;
    }

    QVariant idData = ui->comboBoxProductID->currentData();
    if (!idData.isValid()) {
        QMessageBox::warning(this, "Помилка", "Оберіть товар для видалення!");
        return;
    }

    int productId = idData.toInt();

    QSqlQuery query(db);
    query.prepare("DELETE FROM products WHERE product_id = ?");
    query.addBindValue(productId);

    if (!query.exec()) {
        QMessageBox::warning(this, "Помилка",
                             "Не вдалося видалити товар:\n" + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Успіх", "Товар успішно видалено!");
    int categoryId = ui->comboBoxCategory->currentData().toInt();
    loadProductIDs(categoryId);
}
