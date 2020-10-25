#ifndef PROPERTYWINDOW_H
#define PROPERTYWINDOW_H

#include <QWidget>
#include <MetaObject.h>

namespace Ui {
class PropertyWindow;
}

class PropertyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PropertyWindow(QWidget *parent = nullptr);
    ~PropertyWindow();
    //    void addProperty_layout1(QWidget * widget);
    //    void addProperty_layout2(QWidget * widget);
    //    void addProperty_layout3(QWidget * widget);
    //    void addProperty_layout4(QWidget * widget);
    //    void showTopSceneProperty();
    //    void showSceneProperty();
    //    void showObjectProperty();
signals:


public slots:
    void on_foucsChanged(MetaObject * pfocus);

private slots:

    void on_comboBox_modelPackage_currentIndexChanged(const QString &arg1);

    void on_comboBox_Model_currentIndexChanged(const QString &arg1);

private:
    Ui::PropertyWindow *ui;
    MetaObject * m_pFocus;
};

#endif // PROPERTYWINDOW_H
