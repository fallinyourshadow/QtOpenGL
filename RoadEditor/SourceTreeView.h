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

signals:

public slots:
    void on_modelPressed(const QModelIndex &index);
protected:
    virtual void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;
private:
    Topscene * m_pTopscene;
    QStandardItemModel m_model;
    SceneWindowMenu m_menu;
    MetaObject * m_pFous;
    bool m_isfousUpdated;
};

#endif // SOURCETREE_H
