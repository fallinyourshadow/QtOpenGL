#include "ModelWindow.h"
#include "ui_ModelWindow.h"

ModelWindow::ModelWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelWindow)
{
    ui->setupUi(this);
}

ModelWindow::~ModelWindow()
{
    delete ui;
}
