/********************************************************************************
** Form generated from reading UI file 'ViewWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWWINDOW_H
#define UI_VIEWWINDOW_H

#include <OpenGlWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewWindow
{
public:
    QVBoxLayout *verticalLayout;
    OpenGlWidget *openGLWidget;

    void setupUi(QWidget *ViewWindow)
    {
        if (ViewWindow->objectName().isEmpty())
            ViewWindow->setObjectName(QString::fromUtf8("ViewWindow"));
        ViewWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ViewWindow->sizePolicy().hasHeightForWidth());
        ViewWindow->setSizePolicy(sizePolicy);
        ViewWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 47, 189);"));
        verticalLayout = new QVBoxLayout(ViewWindow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new OpenGlWidget(ViewWindow);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        verticalLayout->addWidget(openGLWidget);


        retranslateUi(ViewWindow);

        QMetaObject::connectSlotsByName(ViewWindow);
    } // setupUi

    void retranslateUi(QWidget *ViewWindow)
    {
        ViewWindow->setWindowTitle(QApplication::translate("ViewWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewWindow: public Ui_ViewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWWINDOW_H
