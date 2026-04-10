
#include "LosCommandUi.h"
namespace LosView
{

    LosCommandUi::LosCommandUi(QWidget *parent) : QDialog(parent)
    {
        initStyle();
        initConnect();
    }



    void LosCommandUi::regis(const QString &display, const QString &cmd)
    {
        L_commands.insert(display, cmd);
        L_lists->addItem(display);
    }



    /**
    - 显示搜索的 框
    */
    void LosCommandUi::showPalette()
    {
        L_searchBox->clear();
        onSearchTextChanged("");
        if (L_lists->count() > 0)
        {
            L_lists->setCurrentRow(0);
        }

        if (parentWidget())
        {
            QPoint globalPos = parentWidget()->mapToGlobal(QPoint(0, 0));
            int x            = globalPos.x() + (parentWidget()->width() - width()) / 2;
            int y            = globalPos.y() + 100;
            move(x, y);
        }
        show();
        L_searchBox->setFocus();
    }



    /**
    - 初始化 央视
    */
    void LosCommandUi::initStyle()
    {
        setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(15, 15, 15, 15);
        QFrame *container = new QFrame(this);
        container->setObjectName("PaletteContainer");
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
        shadow->setBlurRadius(20);
        shadow->setColor(QColor(0, 0, 0, 180));
        shadow->setOffset(0, 5);
        container->setGraphicsEffect(shadow);
        QVBoxLayout *containerLayout = new QVBoxLayout(container);
        containerLayout->setContentsMargins(0, 0, 0, 0);
        containerLayout->setSpacing(0);
        L_searchBox = new QLineEdit(container);
        L_lists     = new QListWidget(container);
        L_searchBox->setPlaceholderText("type a command ...");
        L_searchBox->installEventFilter(this);
        L_lists->setFocusPolicy(Qt::NoFocus);
        containerLayout->addWidget(L_searchBox);
        containerLayout->addWidget(L_lists);
        mainLayout->addWidget(container);
        setFixedSize(630, 380);
        this->setStyleSheet(LosStyle::LosCommandUi_style());
    }



    /**
    - 初始化链接
    */
    void LosCommandUi::initConnect()
    {
        auto &router = LosCore::LosRouter::instance();
        connect(L_searchBox, &QLineEdit::textChanged, this, &LosCommandUi::onSearchTextChanged);
        connect(L_lists, &QListWidget::itemClicked, this, &LosCommandUi::executeSelectedItem);
        connect(&router, &LosCore::LosRouter::_cmd_net_PluginPath, this, &LosCommandUi::onPluginPath);
    }



    /**
    - 文本的 改动
    */
    void LosCommandUi::onSearchTextChanged(const QString &text)
    {
        for (int i = 0; i < L_lists->count(); i++)
        {
            QListWidgetItem *item = L_lists->item(i);
            // 小写
            bool isMatch = item->text().contains(text, Qt::CaseInsensitive);
            item->setHidden(!isMatch);
        }
        for (int i = 0; i < L_lists->count(); ++i)
        {
            if (!L_lists->item(i)->isHidden())
            {
                L_lists->setCurrentRow(i);
                break;
            }
        }
    }



    /**
    - 执行 选中的 item
    */
    void LosCommandUi::executeSelectedItem()
    {
        auto item = L_lists->currentItem();
        if (item && !item->isHidden())
        {
            // 如果
            QString scrip = L_commands.value(item->text());
            hide();
            emit LosCore::LosRouter::instance()._cmd_command_exeScript(scrip);
        }
    }



    /**
    - 解析 这个json
    {
    "id": "perseus-rust",
    "name": "Rust Support For create and build",
    "version": "1.0.0",
    "description": "provides Cargo project creation and building support",
    "contributes": {
        "commands": {
        "rust.create.linux": "./scripts/create.sh",
        "rust.create.windows": "./scripts/create.bat",
        "rust.build.linux": "./scripts/build.sh"
        }
    }
    }
    */
    void LosCommandUi::onPluginPath(const QString &plugin_path)
    {
        // plugin_path =  /home/losangelous/.perseus/extensions/rust-extension
        QFileInfo file(plugin_path);
        if (!file.exists())
        {
            ERR("file:" + plugin_path + " is not exist!", "LosCommandUi");
            return;
        }

        QDir dir(plugin_path);
        QString jsonPath = dir.filePath("package.json");
        QFile f(jsonPath);
        if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ERR("open file failed!", "LosCommandUi");
            return;
        }

        QJsonDocument dic = QJsonDocument::fromJson(f.readAll());
        if (!dic.isObject())
        {
            ERR("dic is not QJsonDocument!", "LosCommandUi");
            return;
        }

        QJsonObject obj = dic.object();
        if (!obj.contains("contributes"))
        {
            ERR("obj is not contain contributes", "LosCommandUi");
            return;
        }

        QJsonObject contributesObj = obj["contributes"].toObject();
        if (!contributesObj.contains("commands"))
        {
            ERR("contributesObj is not contain commands", "LosCommandUi");
            return;
        }

        QJsonObject commandsObj = contributesObj["commands"].toObject();
        for (auto i = commandsObj.begin(); i != commandsObj.end(); i++)
        {
            QString cmdName            = i.key();
            QString scriptRelativePath = i.value().toString();
#ifdef Q_OS_WIN
            if (cmdName.endsWith(".linux"))
                continue;
#else
            if (cmdName.endsWith(".windows"))
                continue;
#endif
            if (scriptRelativePath.startsWith("./"))
            {
                scriptRelativePath = scriptRelativePath.mid(0, 2);
            }
            QString scriptAbsolutePath = QDir(plugin_path).filePath(scriptRelativePath);
            regis(cmdName, scriptAbsolutePath);
        }
    }



    /**
    - 过滤掉 一些 按键
    */
    bool LosCommandUi::eventFilter(QObject *watched, QEvent *event)
    {
        if (watched == L_searchBox && event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            int currentRow      = L_lists->currentRow();

            if (keyEvent->key() == Qt::Key_Down)
            {
                for (int i = currentRow + 1; i < L_lists->count(); ++i)
                {
                    if (!L_lists->item(i)->isHidden())
                    {
                        L_lists->setCurrentRow(i);
                        break;
                    }
                }
                return true;
            }
            else if (keyEvent->key() == Qt::Key_Up)
            {
                for (int i = currentRow - 1; i >= 0; --i)
                {
                    if (!L_lists->item(i)->isHidden())
                    {
                        L_lists->setCurrentRow(i);
                        break;
                    }
                }
                return true;
            }
            else if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
            {
                executeSelectedItem();
                return true;
            }
            else if (keyEvent->key() == Qt::Key_Escape)
            {
                hide();
                return true;
            }
        }
        return QDialog::eventFilter(watched, event);
    }



    void LosCommandUi::focusOutEvent(QFocusEvent *event)
    {
        hide();
        QDialog::focusOutEvent(event);
    }



    bool LosCommandUi::event(QEvent *event)
    {
        if (event->type() == QEvent::WindowDeactivate)
        {
            hide();
        }
        return QDialog::event(event);
    }


} // namespace LosView