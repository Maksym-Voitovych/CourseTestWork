#ifndef DELETE_H
#define DELETE_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Delete;
}

class Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = nullptr, QSqlDatabase database = QSqlDatabase());
    ~Delete();

private slots:
    void onCategoryChanged(int index);
    void onDeleteClicked();

private:
    Ui::Delete *ui;
    QSqlDatabase db;
   void loadProductIDs(int categoryId);
};

#endif // DELETE_H
