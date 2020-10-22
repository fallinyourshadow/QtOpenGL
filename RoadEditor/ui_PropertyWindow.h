/********************************************************************************
** Form generated from reading UI file 'PropertyWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTYWINDOW_H
#define UI_PROPERTYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PropertyWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;

    void setupUi(QWidget *PropertyWindow)
    {
        if (PropertyWindow->objectName().isEmpty())
            PropertyWindow->setObjectName(QString::fromUtf8("PropertyWindow"));
        PropertyWindow->resize(606, 751);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PropertyWindow->sizePolicy().hasHeightForWidth());
        PropertyWindow->setSizePolicy(sizePolicy);
        PropertyWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        verticalLayout = new QVBoxLayout(PropertyWindow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(PropertyWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));

        verticalLayout->addWidget(groupBox);


        retranslateUi(PropertyWindow);

        QMetaObject::connectSlotsByName(PropertyWindow);
    } // setupUi

    void retranslateUi(QWidget *PropertyWindow)
    {
        PropertyWindow->setWindowTitle(QApplication::translate("PropertyWindow", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("PropertyWindow", "property", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PropertyWindow: public Ui_PropertyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTYWINDOW_H
