#include "PropertyWindow.h"
#include "ui_PropertyWindow.h"

PropertyWindow::PropertyWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertyWindow)
{
    ui->setupUi(this);
}

PropertyWindow::~PropertyWindow()
{
    delete ui;
}
