#include "ImageList.h"

#include <QMouseEvent>

ImageList::ImageList(QWidget* p_Parent):
    QListView(p_Parent)
{
    m_ListModel = new QFileSystemModel(p_Parent);
    m_ImageFilter << "*.png" << "*.jpg" << "*.gif" << "*.jpeg";
}

ImageList::~ImageList()
{
}

void ImageList::Init(const QString& p_Path)
{
    m_ListModel->setRootPath(p_Path);
    m_ListModel->setNameFilters(m_ImageFilter);
    setDragEnabled(true);
    setModel(m_ListModel);
}

void ImageList::UpdateListView(const QString& p_Path)
{
    this->setRootIndex(m_ListModel->setRootPath(p_Path));
}

void ImageList::GetFileNameFromListView(const QModelIndex& p_Index)
{
    QString file = m_ListModel->fileInfo(p_Index).absoluteFilePath();
    UpdateListView(file);
    emit UpdateImage(file);
}

