#include "SourceTreeView.h"
#include <QHeaderView>
#include "../Common/Common.h"
#include "Object.h"
#include "SourcePackageManager.h"

SourceTreeView::SourceTreeView(QWidget *parent) : QTreeView(parent)
{
    SourcePackageManager mnager;
    m_isfousUpdated = false;
    m_pFocus = nullptr;

    m_pTopScene = new Topscene;
    ModelPackage * defaultPackage = new ModelPackage("default");//默认模型包
    Model * defaultModel = new Model("default");//默认模型

    defaultModel->loading("default model loading");//加载默认模型数据
    defaultPackage->appendModel("default", defaultModel);//将默认模型加入默认模型包
    mnager.appendModelPackage("default", defaultPackage);//加入管理器
    m_pTopScene->citeModelPackage(mnager.selectModelPackage("default").at(0));//从管理器中查询并引用该模型包
    DEBUG_TITLE << m_pTopScene->modelPackage()->name();


    m_pTopScene->setText("TopScene");
    setModel(&m_model);

    m_model.setHorizontalHeaderLabels(QStringList() << "scene window");
    m_model.setItem(0,m_pTopScene);

    connect(this,&SourceTreeView::pressed, this, &SourceTreeView::on_modelPressed);
    connect(m_menu.addScene(),&QAction::triggered,this,&SourceTreeView::on_addSceneTriggered);
    connect(m_menu.addObject(),&QAction::triggered,this,&SourceTreeView::on_addObjectTriggered);
    connect(m_menu.delCurScene(),&QAction::triggered,this,&SourceTreeView::on_delCurSceneTriggered);
    connect(m_menu.delCurObject(),&QAction::triggered,this,&SourceTreeView::on_delCurObjectTriggered);
}

SourceTreeView::~SourceTreeView()
{

}

Topscene *SourceTreeView::topScene()
{
    return m_pTopScene;
}

void SourceTreeView::on_modelPressed(const QModelIndex &index)
{
    m_pFocus = (MetaObject *)m_model.itemFromIndex(index);
   // DEBUG((quint64)m_model.itemFromIndex(index));
   // DEBUG((quint64)m_pFocus);
    m_isfousUpdated = true;

    Q_EMIT  focusChanged(m_pFocus);
}

void SourceTreeView::on_addSceneTriggered()
{
    Scene * scene = new Scene;
    scene->setText(scene->text().append(rand()%100));
    m_pFocus->setChild(m_pFocus->rowCount(), scene);
}

void SourceTreeView::on_addObjectTriggered()
{
    Object * obj = new Object;
    obj->setText(obj->text().append(rand()%100));
     m_pFocus->setChild(m_pFocus->rowCount(), obj);
}

void SourceTreeView::on_delCurSceneTriggered()
{
    m_pFocus->QStandardItem::parent()->removeRow(m_pFocus->row());
    m_pFocus = nullptr;
}

void SourceTreeView::on_delCurObjectTriggered()
{
    m_pFocus->QStandardItem::parent()->removeRow(m_pFocus->row());
    m_pFocus = nullptr;
}

void SourceTreeView::contextMenuEvent(QContextMenuEvent *event)
{
    if(nullptr == m_pFocus)
        return;
    if(m_isfousUpdated == false)
        return;
    switch (m_pFocus->objectType()) {
    case MetaObject::TOP_SCENE:
    {
        m_menu.showTopSceneMenu();

        break;
    }
    case MetaObject::OBJECT:
    {
        m_menu.showObjectMenu();

        break;
    }
    case MetaObject::SCENE:
    {
        m_menu.showSceneMenu();

        break;
    }
    default:

        break;
    }
    m_menu.move(cursor().pos());
    m_menu.show();
    m_isfousUpdated = false;
}
