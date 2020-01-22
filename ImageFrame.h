#pragma once

#include <QMainWindow>
#include <QFrame>
#include <QLabel>
#include <QWidget>
#include <QImage>
#include <QPointer>

class ImageFrame : public QFrame
{
    Q_OBJECT
public:
    explicit ImageFrame(QWidget* p_Parent = nullptr, QLabel* p_Label = nullptr);
    virtual ~ImageFrame();

    void SetChildLabel(QLabel* p_ImageLabel);
    bool LoadImageAtPath(const QString& p_FileName);

    // Overridden Method(s)
    virtual void resizeEvent(QResizeEvent* p_Event);
    void dropEvent(QDropEvent* p_Event);
    void dragEnterEvent(QDragEnterEvent* p_Event);
    void dragMoveEvent(QDragMoveEvent* p_Event);

public slots:
    void ChangePicture(QString& p_FileName);

private:
    QString m_ImageFile;
    QPointer<QLabel> m_ImageLabel;
    QImage m_Picture;
    bool m_ImageValid;

    void LoadImage(const int& p_Width, const int& p_Height);
};

