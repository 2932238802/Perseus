#pragma once
#include <QString>
#include <qglobal.h>
#include <QStringConverter>

namespace LosCommon
{
    inline const QString DetectAndDecode(const QByteArray &data)
    {
        QString result = QString::fromUtf8(data);

        if (result.contains(QChar(0xFFFD)))
        {

        }
    }

} // namespace LosCommon