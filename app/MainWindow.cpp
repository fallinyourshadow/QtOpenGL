#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddWidget_LayoutLeft(QWidget *anyWidget)
{
    ui->Layout_left->addWidget(anyWidget);
    anyWidget->show();
}

void MainWindow::AddWidget_LayoutRight(QWidget *anyWidget)
{
    ui->Layout_right->addWidget(anyWidget);
    anyWidget->show();
}

void MainWindow::AddWidget_LayoutCentre(QWidget *anyWidget)
{
    ui->Layout_centre->addWidget(anyWidget);
    anyWidget->show();
}

void MainWindow::AddWidget_LayoutTop(QWidget *anyWidget)
{
    ui->Layout_top->addWidget(anyWidget);
    anyWidget->show();
}




