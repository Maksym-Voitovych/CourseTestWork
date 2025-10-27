#ifndef ADDCATEGORIES_H
#define ADDCATEGORIES_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class AddCategories;
}

class AddCategories : public QDialog
{
    Q_OBJECT

public:
    explicit AddCategories(QWidget *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~AddCategories();

private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonClose_clicked();
    void on_pushButtonDelete_clicked();
private:
    Ui::AddCategories *ui;
    QSqlDatabase database;
};

#endif // ADDCATEGORIES_H
