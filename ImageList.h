#pragma once

#include <QListView>
#include <QFileSystemModel>
#include <qdebug.h>
#include <QDrag>
#include <QMimeData>
#include <QPixmap>
#include <QPointer>

class ImageList : public QListView
{
    Q_OBJECT

public:
    explicit ImageList(QWidget* p_Parent = nullptr);
    virtual ~ImageList();

    void Init(const QString& p_Path);
    void UpdateListView(const QString& p_Path);
    void GetFileNameFromListView(const QModelIndex& p_Index);

signals:
    void UpdateImage(QString& p_Filename);

private:
    QStringList m_ImageFilter;
    QPointer<QFileSystemModel> m_ListModel;

};

