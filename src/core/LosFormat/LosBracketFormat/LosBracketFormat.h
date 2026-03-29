#pragma once
#include <qevent.h>
#include <QPlainTextEdit>

namespace LosCore
{

class LosBracketFormat
{
  public:
    static void dealEvent(QPlainTextEdit* editor , QKeyEvent *event);
};
} // namespace LosCore