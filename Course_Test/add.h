#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Add;
}

class Add : public QDialog
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr, QSqlDatabase database = QSqlDatabase());
    ~Add();

private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonClose_clicked();

private:
    Ui::Add *ui;
    QSqlDatabase db;
};

#endif // ADD_H
