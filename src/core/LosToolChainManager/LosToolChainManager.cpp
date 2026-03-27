
#include "LosToolChainManager.h"
#include "common/constants/ConstantsClass.h"

namespace LosCore
{

LosToolChainManager::LosToolChainManager(QObject *parent) : QObject{parent}
{
    initConfig();
}


/**
- 检测语言
*/
void onCheckToolchain(LosCommon::LosToolChain_Constants::LosLanguage) {}


/**
- 初始化 格式
*/
void LosToolChainManager::initConfig()
{
    LOS_languageToConfig.insert(LosCommon::LosToolChain_Constants::LosLanguage::CXX,
                                {.LOS_language  = LosCommon::LosToolChain_Constants::LosLanguage::CXX,
                                 .L_name        = "C++ (g++ / clang++)",
                                 .L_exeName     = QStringList{"g++", "clang++"},
                                 .L_version     = "--version",
                                 .L_validateKey = "g++",
                                 .L_downUrl     = "https://www.msys2.org/"});

    LOS_languageToConfig.insert(LosCommon::LosToolChain_Constants::LosLanguage::RUST,
                                {.LOS_language  = LosCommon::LosToolChain_Constants::LosLanguage::RUST,
                                 .L_name        = "Rust (cargo)",
                                 .L_exeName     = QStringList{"cargo"},
                                 .L_version     = "--version",
                                 .L_validateKey = "cargo",
                                 .L_downUrl     = "https://rustup.rs/"});

    LOS_languageToConfig.insert(LosCommon::LosToolChain_Constants::LosLanguage::PYTHON,
                                {.LOS_language  = LosCommon::LosToolChain_Constants::LosLanguage::PYTHON,
                                 .L_name        = "Python 3",
                                 .L_exeName     = QStringList{"python3", "python"},
                                 .L_version     = "--version",
                                 .L_validateKey = "Python",
                                 .L_downUrl     = "https://www.python.org/downloads/"});
}



}; // namespace LosCore