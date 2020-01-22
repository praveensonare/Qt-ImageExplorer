#pragma once

#include <QMainWindow>
#include <QTreeView>
#include <QListView>
#include <QFileSystemModel>
#include <QtWidgets/QMainWindow>
#include <QPointer>

class DiskExplorer : public QMainWindow
{
    Q_OBJECT
public:
    explicit DiskExplorer(QWidget* p_Parent = nullptr, QTreeView* p_TreeView=nullptr);
    ~DiskExplorer();

    QString OnTreeClick(const QModelIndex& p_Index);
signals:

public slots:
    void ChangeFocus(QString& p_Path);

private:
    QPointer<QTreeView> m_TreeView;
    QPointer<QFileSystemModel> m_TreeModel;

};

