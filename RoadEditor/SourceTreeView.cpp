#include "SourceTreeView.h"
#include <QHeaderView>
#include "../Common/Common.h"
SourceTreeView::SourceTreeView(QWidget *parent) : QTreeView(parent)
{
    m_isfousUpdated = false;
    m_pFous = nullptr;
    m_pTopscene = new Topscene;
    m_pTopscene->setText("TopScene");
    setModel(&m_model);

    m_model.setHorizontalHeaderLabels(QStringList() << "scene window");
    m_model.setItem(0,m_pTopscene);

    connect(this,&SourceTreeView::pressed, this, &SourceTreeView::on_modelPressed);


}

SourceTreeView::~SourceTreeView()
{

}

void SourceTreeView::on_modelPressed(const QModelIndex &index)
{
    m_pFous = (MetaObject *)m_model.itemFromIndex(index);
    m_isfousUpdated = true;
    DEBUG((quint64)m_pFous);
}

void SourceTreeView::contextMenuEvent(QContextMenuEvent *event)
{
    if(nullptr == m_pFous)
        return;
    if(m_isfousUpdated == false)
        return;
    switch (m_pFous->objectType()) {
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
