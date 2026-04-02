

#include "LosRustcRunner.h"
#include "common/constants/ConstantsStr.h"
#include "core/LosRunner/LosAbstractRunner/LosAbstractRunner.h"
#include "core/LosState/LosState.h"
#include "models/LosFilePath/LosFilePath.h"
#include <qprocess.h>

namespace LosCore
{
/**
- construct
*/
LosRustcRunner::LosRustcRunner(QObject *parent) : LosAbstractRunner(parent)
{
    L_runner = new QProcess(this);
    L_rustc  = new QProcess(this);
}
LosRustcRunner::~LosRustcRunner()
{
    stop();
}



/**
- 暂停
*/
void LosRustcRunner::stop()
{
    if (L_rustc->state() != QProcess::NotRunning)
    {
        L_rustc->kill();
    }
    if (L_runner->state() != QProcess::NotRunning)
    {
        L_runner->kill();
    }
}



/**
- 开始运行
-
*/
void LosRustcRunner::start(const QString &file_path)
{
    LOS_targetFilePath.loadFile(file_path);
    LosModel::LosFilePath dir(
        LosState::instance().get<LosModel::LosFilePath>(LosCommon::LosState_Constants::SG_STR::PROJECT_DIR));
    
#ifdef Q_OS_WIN
#elif defined(Q_OS_LINUX) || defined(Q_OS_MAC)
        // output / rust
    // L_outPutPath = dir.getAbsolutePath() + QDir::separator() +     
#else
#endif
}



/**
- 设置 可执行文件的位置
- 这个必须 是要 先 执行的
*/
void LosRustcRunner::setExePath(const QString &exe_path)
{
    L_exePath = exe_path;
}

} // namespace LosCore