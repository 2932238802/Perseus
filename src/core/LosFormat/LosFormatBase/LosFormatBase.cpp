
#include "LosFormatBase.h"
namespace LosCore
{
LosFormatBase::LosFormatBase(QObject *parent) : QObject{parent}
{
    L_process = new QProcess(this);
}

} // namespace LosCore