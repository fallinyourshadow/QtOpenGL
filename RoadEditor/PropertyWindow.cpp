#include "PropertyWindow.h"
#include "ui_PropertyWindow.h"
#include "../Common/Common.h"
#include "SourcePackageManager.h"

PropertyWindow::PropertyWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertyWindow)
{
    ui->setupUi(this);
    m_pFocus = nullptr;

}

PropertyWindow::~PropertyWindow()
{
    delete ui;
}

//void PropertyWindow::addProperty_layout1(QWidget *widget)
//{
//    QWidget * temp = ui->verticalLayout_1->widget();
//    if(nullptr != temp)
//        ui->verticalLayout_1->removeWidget(temp);
//    ui->verticalLayout_1->addWidget(widget);
//}

//void PropertyWindow::addProperty_layout2(QWidget *widget)
//{
//    QWidget * temp = ui->verticalLayout_2->widget();
//    if(nullptr != temp)
//        ui->verticalLayout_2->removeWidget(temp);
//    ui->verticalLayout_2->addWidget(widget);
//}

//void PropertyWindow::addProperty_layout3(QWidget *widget)
//{
//    QWidget * temp = ui->verticalLayout_3->widget();
//    if(nullptr != temp)
//        ui->verticalLayout_3->removeWidget(temp);
//    ui->verticalLayout_3->addWidget(widget);
//}

//void PropertyWindow::addProperty_layout4(QWidget *widget)
//{
//    QWidget * temp = ui->verticalLayout_4->widget();
//    if(nullptr != temp)
//        ui->verticalLayout_4->removeWidget(temp);
//    ui->verticalLayout_4->addWidget(widget);
//}

void PropertyWindow::on_foucsChanged(MetaObject *pfocus)
{
    m_pFocus = pfocus;

    //DEBUG_TITLE <<  m_pFocus->modelPackage();
    ui->comboBox_Model->clear();
    if(nullptr == m_pFocus->modelPackage())
        return;
    QStringList modelList;
    Model * v = nullptr;
    QHash<QString,Model *> package = m_pFocus->modelPackage()->modelPackage();
    foreach(v,package)
    {
        modelList.append(v->name());
    }
    ui->comboBox_Model->addItems(modelList);

}

//void PropertyWindow::showTopSceneProperty()
//{

//}


void PropertyWindow::on_comboBox_modelPackage_currentIndexChanged(const QString &arg1)
{
    SourcePackageManager manager;
    QList<ModelPackage *> packages;
    packages = manager.selectModelPackage(arg1);
    if(0 == packages.size())
        return;
    m_pFocus->citeModelPackage(packages.value(0));
}

void PropertyWindow::on_comboBox_Model_currentIndexChanged(const QString &arg1)
{
    if(nullptr == m_pFocus)
        return;
    ModelPackage * package = m_pFocus->modelPackage();
    if(nullptr == package)
        return;
    Model * model = package->selectModel(arg1);
    if(nullptr == model)
        return;
    m_pFocus->citeModel(model);
   // DEBUG(model->name());
}
