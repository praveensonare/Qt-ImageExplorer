#include "DiskExplorer.h"

#include <QDebug>

DiskExplorer::DiskExplorer(QWidget* p_Parent, QTreeView* p_TreeView)
    : QMainWindow(p_Parent)
    , m_TreeView(p_TreeView)
{
    m_TreeModel = new QFileSystemModel(p_Parent);
    QString defaultPath = "/";
    m_TreeModel->setRootPath(defaultPath);
    m_TreeView->setModel(m_TreeModel);
    m_TreeView->setDragEnabled(true);
    m_TreeView->setRootIndex(m_TreeModel->index(defaultPath));
    m_TreeView->setColumnWidth(0, 200);
    m_TreeView->hideColumn(1);
    m_TreeView->hideColumn(2);
    //m_TreeView->hideColumn(0);
}

DiskExplorer::~DiskExplorer()
{
    if (m_TreeModel)
    {
        delete m_TreeModel;
    }
}

QString DiskExplorer::OnTreeClick(const QModelIndex& p_Index)
{
    return m_TreeModel->fileInfo(p_Index).absoluteFilePath();
}

void DiskExplorer::ChangeFocus(QString& p_Path)
{
    m_TreeView->setCurrentIndex(m_TreeModel->index(p_Path));
}
