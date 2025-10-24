/********************************************************************************
** Form generated from reading UI file 'delete.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_H
#define UI_DELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Delete
{
public:
    QLabel *label;
    QComboBox *comboBoxCategory;
    QLabel *label_2;
    QComboBox *comboBoxProductID;
    QPushButton *pushButtonClose;
    QPushButton *pushButtonDelete;

    void setupUi(QDialog *Delete)
    {
        if (Delete->objectName().isEmpty())
            Delete->setObjectName("Delete");
        Delete->resize(240, 185);
        label = new QLabel(Delete);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 61, 21));
        comboBoxCategory = new QComboBox(Delete);
        comboBoxCategory->setObjectName("comboBoxCategory");
        comboBoxCategory->setGeometry(QRect(80, 20, 101, 24));
        label_2 = new QLabel(Delete);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 61, 21));
        comboBoxProductID = new QComboBox(Delete);
        comboBoxProductID->setObjectName("comboBoxProductID");
        comboBoxProductID->setGeometry(QRect(80, 60, 101, 24));
        pushButtonClose = new QPushButton(Delete);
        pushButtonClose->setObjectName("pushButtonClose");
        pushButtonClose->setGeometry(QRect(140, 130, 80, 24));
        pushButtonDelete = new QPushButton(Delete);
        pushButtonDelete->setObjectName("pushButtonDelete");
        pushButtonDelete->setGeometry(QRect(20, 130, 80, 24));

        retranslateUi(Delete);

        QMetaObject::connectSlotsByName(Delete);
    } // setupUi

    void retranslateUi(QDialog *Delete)
    {
        Delete->setWindowTitle(QCoreApplication::translate("Delete", "\320\222\320\270\320\264\320\260\320\273\320\265\320\275\320\275\321\217 \320\242\320\276\320\262\320\260\321\200\321\203", nullptr));
        label->setText(QCoreApplication::translate("Delete", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\321\226\321\217:", nullptr));
        label_2->setText(QCoreApplication::translate("Delete", "ID \321\202\320\276\320\262\320\260\321\200\321\203:", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("Delete", "\320\227\320\260\320\272\321\200\320\270\321\202\320\270", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("Delete", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Delete: public Ui_Delete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_H
