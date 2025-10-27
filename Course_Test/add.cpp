#include "add.h"
#include "ui_add.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

Add::Add(QWidget *parent, QSqlDatabase database)
    : QDialog(parent)
    , ui(new Ui::Add)
    , db(database)
{
    ui->setupUi(this);
    setWindowTitle("Додавання товару");
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
}
Add::~Add()
{
    delete ui;
}
void Add::on_pushButtonClose_clicked()
{
    close();
}
void Add::on_pushButtonAdd_clicked()
{
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Помилка", "База даних не підключена!");
        return;
    }
    int categoryId = ui->comboBoxCategory->currentData().toInt();
    QString brand = ui->lineEditBrand->text().trimmed();
    QString model = ui->lineEditModel->text().trimmed();
    QString priceStr = ui->lineEditPrice->text().trimmed();
    QString yearStr = ui->lineEditYear->text().trimmed();
    QString stockStr = ui->lineEditStock->text().trimmed();
    if (brand.isEmpty() || model.isEmpty() || priceStr.isEmpty() ||
        yearStr.isEmpty() || stockStr.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Будь ласка, заповніть усі поля!");
        return;
    }

    bool okPrice, okYear, okStock;
    double price = priceStr.toDouble(&okPrice);
    int year = yearStr.toInt(&okYear);
    int stock = stockStr.toInt(&okStock);

    if (!okPrice || !okYear || !okStock) {
        QMessageBox::warning(this, "Помилка", "Некоректні числові значення!");
        return;
    }
    QSqlQuery query(db);
    query.prepare(R"(
        INSERT INTO products (category_id, brand, model, price, release_year, stock)
        VALUES (?, ?, ?, ?, ?, ?)
    )");
    query.addBindValue(categoryId);
    query.addBindValue(brand);
    query.addBindValue(model);
    query.addBindValue(price);
    query.addBindValue(year);
    query.addBindValue(stock);

    if (!query.exec()) {
        QMessageBox::warning(this, "Помилка",
                             "Не вдалося додати товар:\n" + query.lastError().text());
        qDebug() << "SQL помилка:" << query.lastError().text();
        return;
    }

    QMessageBox::information(this, "Успіх", "Товар успішно додано!");
    close();
}
