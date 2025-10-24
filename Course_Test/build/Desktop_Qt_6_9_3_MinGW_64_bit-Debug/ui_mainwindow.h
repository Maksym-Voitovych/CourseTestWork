/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QToolButton *buttonBack;
    QTableView *tableViewProducts;
    QPushButton *pushButtonDeleteProduct;
    QPushButton *pushButtonAddProduct;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(840, 357);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        buttonBack = new QToolButton(centralwidget);
        buttonBack->setObjectName("buttonBack");

        verticalLayout->addWidget(buttonBack);

        tableViewProducts = new QTableView(centralwidget);
        tableViewProducts->setObjectName("tableViewProducts");

        verticalLayout->addWidget(tableViewProducts);

        pushButtonDeleteProduct = new QPushButton(centralwidget);
        pushButtonDeleteProduct->setObjectName("pushButtonDeleteProduct");

        verticalLayout->addWidget(pushButtonDeleteProduct);

        pushButtonAddProduct = new QPushButton(centralwidget);
        pushButtonAddProduct->setObjectName("pushButtonAddProduct");

        verticalLayout->addWidget(pushButtonAddProduct);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonBack->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButtonDeleteProduct->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \321\202\320\276\320\262\320\260\321\200:", nullptr));
        pushButtonAddProduct->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \321\202\320\276\320\262\320\260\321\200:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
