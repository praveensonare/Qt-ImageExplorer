#include "ImageFrame.h"

#include <QDragEnterEvent>
#include <QMimeData>

ImageFrame::ImageFrame(QWidget* parent, QLabel* label):
    QFrame(parent)
    , m_ImageLabel(label)
    , m_Picture(nullptr)
    , m_ImageValid(false)
{
    //Setting color while for Frame
    setStyleSheet("background-color: rgb(255, 255, 255);");
}

ImageFrame::~ImageFrame()
{

}

void ImageFrame::resizeEvent(QResizeEvent* p_Event)
{
    LoadImage(width(),height());
}

void ImageFrame::SetChildLabel(QLabel* p_ImageLabel)
{
    m_ImageLabel = p_ImageLabel;
    m_ImageLabel->setAcceptDrops(true);
}

bool ImageFrame::LoadImageAtPath(const QString& p_FileName)
{
    m_ImageFile = p_FileName;
    m_ImageValid = m_Picture.load(m_ImageFile);
    if (m_ImageValid)
    {
        LoadImage(width(), height());
    }
    return m_ImageValid;

}

void ImageFrame::LoadImage(const int& p_Width, const int& p_Height)
{
    if (m_ImageValid)
    {
        m_ImageLabel->setAlignment(Qt::AlignCenter);
        m_ImageLabel->setPixmap(QPixmap::fromImage(m_Picture.scaled(p_Width, p_Height, Qt::KeepAspectRatio)));
    }
}

void ImageFrame::dropEvent(QDropEvent* p_Event)
{
    QString imPath = p_Event->mimeData()->text();
    QString toTrim = "file:///";
    if(imPath.startsWith(toTrim))
    {
        imPath = imPath.mid(toTrim.length()-1,
                            imPath.length()-toTrim.length()+1);
    }
    LoadImageAtPath(imPath);
    p_Event->acceptProposedAction();
}

void ImageFrame::dragEnterEvent(QDragEnterEvent* p_Event)
{
    if (p_Event->source() == this)
    {
        p_Event->setDropAction(Qt::MoveAction);
        p_Event->accept();
    }
    else
    {
        p_Event->acceptProposedAction();
    }
}

void ImageFrame::dragMoveEvent(QDragMoveEvent* p_Event)
{
    if (p_Event->source() == this) {
        p_Event->setDropAction(Qt::MoveAction);
        p_Event->accept();
    }
    else
    {
        p_Event->acceptProposedAction();
    }
}

void ImageFrame::ChangePicture(QString& p_FileName)
{
    LoadImageAtPath(p_FileName);
}

