#pragma once

#include "../ImageExplorer/ImageFrame.h"
#include "../ImageExplorer/DiskExplorer.h"

#include <QMainWindow>
#include <QPointer>

QT_BEGIN_NAMESPACE
namespace Ui { class ImageExplorer; }
QT_END_NAMESPACE

class ImageExplorer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageExplorer(QWidget* p_Parent = nullptr);
    ~ImageExplorer();

private slots:
    void on_treeView_clicked(const QModelIndex& index);
    void on_imListView_doubleClicked(const QModelIndex& index);

private:
    Ui::ImageExplorer* m_UI;
    QPointer<ImageFrame> m_ImageFrame;
    QPointer<DiskExplorer> m_DiskExplorer;

    void SetEqualPartition();
};

