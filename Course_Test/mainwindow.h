#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAddProduct_clicked();
    void on_pushButtonDeleteProduct_clicked();
    void onCategorySelected(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QString currentCategory;

    void connectToDatabase();
    void loadCategories();
    void loadProducts(QString category);
};

#endif // MAINWINDOW_H
