#include "addcategories.h"
#include "ui_addcategories.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

AddCategories::AddCategories(QWidget *parent, QSqlDatabase db)
    : QDialog(parent),
    ui(new Ui::AddCategories),
    database(db)
{
    ui->setupUi(this);

    connect(ui->pushButtonClose, &QPushButton::clicked, this, &AddCategories::on_pushButtonClose_clicked);
}

AddCategories::~AddCategories()
{
    delete ui;
}

void AddCategories::on_pushButtonAdd_clicked()
{
    QString categoryName = ui->lineEditCategoryName->text().trimmed();
    if (categoryName.isEmpty() || !database.isOpen())
        return;

    QSqlQuery query(database);
    query.prepare("INSERT INTO categories (category_name) VALUES (?)");
    query.addBindValue(categoryName);
    if (query.exec())
        accept();
}


void AddCategories::on_pushButtonDelete_clicked()
{
    QString categoryName = ui->lineEditCategoryName->text().trimmed();

    if (categoryName.isEmpty()) return;
    if (!database.isOpen()) return;

    QSqlQuery query(database);
    query.prepare("DELETE FROM categories WHERE category_name = ?");
    query.addBindValue(categoryName);

    if (!query.exec()) {
        qDebug() << "Помилка видалення:" << query.lastError().text();
        return;
    }

    qDebug() << "Категорія видалена:" << categoryName;
    accept();
    }



void AddCategories::on_pushButtonClose_clicked()
{
    reject();
}
