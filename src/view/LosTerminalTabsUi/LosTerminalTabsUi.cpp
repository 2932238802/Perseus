#include "LosTerminalTabsUi.h"
#include "view/LosTerminalUi/LosTerminalUi.h"
#include <qwidget.h>

namespace LosView
{

LosTerminalTabsUi::LosTerminalTabsUi(QWidget *parent) : QTabWidget(parent)
{
    initStyle();
}



/**
- 初始化 样式
*/
void LosTerminalTabsUi::initStyle()
{
    // 能被关闭
    setTabsClosable(true);
    setDocumentMode(true);

    // 清空一开始的站位
    clear();

    addTab(new QWidget(), "+");

    // 当前空间 里面的 所有 子控件
    // 右侧 关闭按钮 (×)、菜单按钮、扩展操作
    // 左侧 图标、状态红点、固定按钮、类型标识
    tabBar()->setTabButton(0, QTabBar::RightSide, nullptr);
    connect(this, &QTabWidget::currentChanged, this,
            [this](int index)
            {
                int lastIndex = count() - 1;
                if (index == lastIndex)
                {
                    // 任务 队列
                    QTimer::singleShot(0, this, [this]() { addNewTerminal(); });
                }
            });

    connect(this, &QTabWidget::tabCloseRequested, this,
            [this](int index)
            {
                int lastIndex = count() - 1;
                if (index == lastIndex)
                    return;
                QWidget *w = widget(index);
                removeTab(index);
                w->deleteLater();
            });
    addNewTerminal();
}



/**
- 增加 终端
*/
void LosTerminalTabsUi::addNewTerminal()
{
    LosView::LosTerminalUi *newOne = new LosView::LosTerminalUi(this);
    int insertIndex                = count() - 1;
    // 0 1 2
    if (insertIndex < 0)
        insertIndex = 0;

    // 命名
    int number = insertIndex + 1;
    this->blockSignals(true);
    insertTab(insertIndex, newOne, QString("sh - %1").arg(number));
    setCurrentIndex(insertIndex);
    this->blockSignals(false);
}
} // namespace LosView