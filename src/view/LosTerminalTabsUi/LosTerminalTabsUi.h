#pragma once


#include <QTabBar>
#include <qobject.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <QTimer>

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
};
} // namespace LosView
