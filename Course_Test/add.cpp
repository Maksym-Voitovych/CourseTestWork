#include "add.h"
#include "ui_add.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Add::Add(QWidget *parent, QSqlDatabase database)
    : QDialog(parent)
    , ui(new Ui::Add)
    , db(database)
{
    ui->setupUi(this);
    setWindowTitle("Додавання товару");
    ui->comboBoxCategory->clear();
    ui->comboBoxCategory->addItem("Смартфони", "smartphones");
    ui->comboBoxCategory->addItem("Ноутбуки",  "laptops");
    ui->comboBoxCategory->addItem("Планшети",  "tablets");
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

    QString category = ui->comboBoxCategory->currentData().toString();
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
    QString sql = R"(
        INSERT INTO products (category, brand, model, price, release_year, stock)
        VALUES (?, ?, ?, ?, ?, ?)
    )";
    query.prepare(sql);
    query.addBindValue(category);
    query.addBindValue(brand);
    query.addBindValue(model);
    query.addBindValue(price);
    query.addBindValue(year);
    query.addBindValue(stock);

    qDebug() << "INSERT:" << sql;

    if (!query.exec()) {
        QMessageBox::warning(this, "Помилка",
                             "Не вдалося додати товар:\n" + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Успіх", "Товар успішно додано!");
    close();
}
