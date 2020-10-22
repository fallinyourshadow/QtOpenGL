#ifndef SOURCETREE_H
#define SOURCETREE_H

#include <QObject>
#include <QTreeView>

class SourceTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit SourceTreeView(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // SOURCETREE_H
