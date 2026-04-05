#include "LosLineNumberUi.h"

namespace LosView
{
LosLineNumberUi::LosLineNumberUi(LosEditorUi *line) : QWidget(line), LOS_editor(line) {}



/**
- 合适的  尺寸
*/
QSize LosLineNumberUi::sizeHint() const
{
    return QSize(LOS_editor->getLineNumberWidth(), 0);
}



/**
- 重绘
*/
void LosLineNumberUi::paintEvent(QPaintEvent *event)
{
    LOS_editor->lineNumberAreaPaintEvent(event);
}


} // namespace LosView