#ifndef SOURCETREE_H
#define SOURCETREE_H

#include <QObject>
#include <QTreeView>
#include <QAction>
#include <Topscene.h>
#include "SceneWindowMenu.h"
#include <QContextMenuEvent>

class SourceTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit SourceTreeView(QWidget *parent = nullptr);
    ~SourceTreeView();
    Topscene * topScene();
signals:
    void focusChanged(MetaObject * m_pFocus);
public slots:
    void on_modelPressed(const QModelIndex &index);
    void on_addSceneTriggered();
    void on_addObjectTriggered();
    void on_delCurSceneTriggered();
    void on_delCurObjectTriggered();
protected:
    virtual void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;
private:
    Topscene * m_pTopScene;
    QStandardItemModel m_model;
    SceneWindowMenu m_menu;
    MetaObject * m_pFocus;

    bool m_isfousUpdated;
};

#endif // SOURCETREE_H
