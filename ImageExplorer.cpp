#include "ImageExplorer.h"
#include "ui_imageexplorer.h"

#include <QList>

ImageExplorer::ImageExplorer(QWidget* p_Parent)
    : QMainWindow(p_Parent)
    , m_UI(new Ui::ImageExplorer)
{
    m_UI->setupUi(this);
    SetEqualPartition();

    m_DiskExplorer = new DiskExplorer(this, m_UI->treeView);
    m_UI->imageFrame->SetChildLabel(m_UI->imageLabel);
    m_UI->imageFrame->setAcceptDrops(true);
    m_UI->imageLabel->setAcceptDrops(true);

    m_UI->imListView->Init("");

    connect(m_UI->imListView, &ImageList::UpdateImage,
            m_UI->imageFrame, &ImageFrame::ChangePicture);

    connect(m_UI->imListView, &ImageList::UpdateImage,
            m_DiskExplorer, &DiskExplorer::ChangeFocus);
}

ImageExplorer::~ImageExplorer()
{
    delete m_UI;
}


void ImageExplorer::on_treeView_clicked(const QModelIndex& index)
{
    QString fileName = m_DiskExplorer->OnTreeClick(index);
    m_UI->imListView->UpdateListView(fileName);
}

void ImageExplorer::on_imListView_doubleClicked(const QModelIndex& index)
{
    m_UI->imListView->GetFileNameFromListView(index);
}

void ImageExplorer::SetEqualPartition()
{
    QList<int> qList;
    int count = m_UI->splitter->count();
    for(int part = 0; part < count; ++part)
    {
        qList.append(width()/count);
    }
    m_UI->splitter->setSizes(qList);
    return;
}
