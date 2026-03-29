

#include "core/LosFormat/LosBracketFormat/LosBracketFormat.h"
#include <qhash.h>
#include <qobject.h>

namespace LosCore
{
void LosBracketFormat::dealEvent(QPlainTextEdit *editor, QKeyEvent *event)
{
    static const QHash<QChar, QChar> AUTO_CLOSE_MAP{{'{', '}'}, {'[', ']'}, {'(', ')'}};
    if (!editor || event->text().isEmpty())
    {
        return;
    }
    const QChar inputChar = event->text().at(0);
    if (!AUTO_CLOSE_MAP.contains(inputChar))
    {
        return;
    }
    QTextCursor cursor = editor->textCursor();
    cursor.insertText( AUTO_CLOSE_MAP[inputChar]);
    cursor.movePosition(QTextCursor::PreviousCharacter);
    editor->setTextCursor(cursor);
}

} // namespace LosCore