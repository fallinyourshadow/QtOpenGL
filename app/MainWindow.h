#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void AddWidget_LayoutLeft(QWidget * anyWidget);
    void AddWidget_LayoutRight(QWidget * anyWidget);
    void AddWidget_LayoutCentre(QWidget * anyWidget);
    void setMenueBar(QList<QMenu *> actionList);
    //void AddWidget_LayoutTop(QWidget * anyWidget);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
