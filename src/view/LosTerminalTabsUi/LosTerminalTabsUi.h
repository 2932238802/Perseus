#pragma once


#include <QTabBar>
#include <QTimer>
#include <qobject.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <QToolButton> 
#include "core/LosLog/LosLog.h"

namespace LosView
{
class LosTerminalTabsUi : public QTabWidget
{
    Q_OBJECT
  public:
    explicit LosTerminalTabsUi(QWidget *parent = nullptr);
    ~LosTerminalTabsUi() = default;


  private:
    void initStyle();

  private: // tool
    void addNewTerminal();

  private:
    QSet<int> L_usedTerminalIds;
};
} // namespace LosView
