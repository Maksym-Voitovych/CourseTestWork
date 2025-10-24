/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBoxCategory;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEditBrand;
    QLineEdit *lineEditModel;
    QLineEdit *lineEditPrice;
    QLineEdit *lineEditYear;
    QLineEdit *lineEditStock;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonClose;

    void setupUi(QDialog *Add)
    {
        if (Add->objectName().isEmpty())
            Add->setObjectName("Add");
        Add->resize(588, 166);
        widget = new QWidget(Add);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(9, 9, 581, 151));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 2);

        comboBoxCategory = new QComboBox(widget);
        comboBoxCategory->setObjectName("comboBoxCategory");

        gridLayout->addWidget(comboBoxCategory, 0, 2, 1, 2);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 1, 3, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 1, 4, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 1, 5, 1, 1);

        lineEditBrand = new QLineEdit(widget);
        lineEditBrand->setObjectName("lineEditBrand");

        gridLayout->addWidget(lineEditBrand, 2, 0, 1, 1);

        lineEditModel = new QLineEdit(widget);
        lineEditModel->setObjectName("lineEditModel");

        gridLayout->addWidget(lineEditModel, 2, 1, 1, 2);

        lineEditPrice = new QLineEdit(widget);
        lineEditPrice->setObjectName("lineEditPrice");

        gridLayout->addWidget(lineEditPrice, 2, 3, 1, 1);

        lineEditYear = new QLineEdit(widget);
        lineEditYear->setObjectName("lineEditYear");

        gridLayout->addWidget(lineEditYear, 2, 4, 1, 1);

        lineEditStock = new QLineEdit(widget);
        lineEditStock->setObjectName("lineEditStock");

        gridLayout->addWidget(lineEditStock, 2, 5, 1, 1);

        pushButtonAdd = new QPushButton(widget);
        pushButtonAdd->setObjectName("pushButtonAdd");

        gridLayout->addWidget(pushButtonAdd, 3, 0, 1, 1);

        pushButtonClose = new QPushButton(widget);
        pushButtonClose->setObjectName("pushButtonClose");

        gridLayout->addWidget(pushButtonClose, 3, 5, 1, 1);


        retranslateUi(Add);

        QMetaObject::connectSlotsByName(Add);
    } // setupUi

    void retranslateUi(QDialog *Add)
    {
        Add->setWindowTitle(QCoreApplication::translate("Add", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Add", "\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\321\226\321\216 \320\264\320\273\321\217 \320\264\320\276\320\264\320\260\320\262\320\260\320\275\320\275\321\217 \321\202\320\276\320\262\320\260\321\200\321\203:", nullptr));
        label_2->setText(QCoreApplication::translate("Add", "\320\221\321\200\320\265\320\275\320\264", nullptr));
        label_3->setText(QCoreApplication::translate("Add", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("Add", "\320\246\321\226\320\275\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("Add", "\320\240\321\226\320\272 \320\262\320\270\320\277\321\203\321\201\320\272\321\203", nullptr));
        label_6->setText(QCoreApplication::translate("Add", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("Add", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\320\270 \321\202\320\276\320\262\320\260\321\200", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("Add", "\320\227\320\260\320\272\321\200\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add: public Ui_Add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
