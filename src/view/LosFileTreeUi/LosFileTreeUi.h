#pragma once
#include "core/LosLog/LosLog.h"
#include "core/LosRouter/LosRouter.h"
#include "models/LosFileNode/LosFileNode.h"
#include "models/LosFilePath/LosFilePath.h"
#include "models/LosFileTreeModel/LosFileTreeModel.h"
#include <QAction>
#include <QClipboard>
#include <QDir>
#include <QFileInfo>
#include <QGuiApplication>
#include <QInputDialog>
#include <QMenu>
#include <QMessageBox>
#include <QMimeData>
#include <QObject>
#include <QPoint>
#include <qevent.h>
#include <qfiledialog.h>
#include <qguiapplication.h>
#include <qlineedit.h>
#include <qmimedata.h>
#include <qtmetamacros.h>
#include <qtreeview.h>
#include <qurl.h>
#include <qwidget.h>

namespace LosView
{
class LosFileTreeUi : public QTreeView
{
    Q_OBJECT
  public:
    explicit LosFileTreeUi(QWidget *parent = nullptr);
    ~LosFileTreeUi() = default;

  public: // tool
    void updateExplorer(LosModel::LosFileTreeModel *);
    void copyFileOrFolder(const QString &, const QString &);
    void deleteFileOrFolder(const QString &);
    bool expandToFile(const QString &);

  public slots: // chs
    void onCustomContextMenu(const QPoint &pos);

  private:
    void initConnect();
    void initStyle();

  private: // innner tool
    QModelIndex findAndExpand(LosModel::LosFileNode *, const QString &, const QModelIndex &);
};
} // namespace LosView