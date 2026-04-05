#include "LosGotoLinePopupUi.h"
#include <QHBoxLayout>
#include <QIntValidator>
#include <QLabel>

namespace LosView
{
LosGotoLinePopupUi::LosGotoLinePopupUi(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    QLabel *label = new QLabel("Go to line:");
    label->setStyleSheet("color: #a6adc8; font-size: 13px;");

    L_lineEdit = new QLineEdit();
    L_lineEdit->setValidator(new QIntValidator(1, INT_MAX, L_lineEdit));
    L_lineEdit->setStyleSheet(R"(
        QLineEdit { 
            background-color: #313244; 
            border: 1px solid #45475a; 
            border-radius: 4px; 
            padding: 4px 8px; 
            color: #ffffff; 
            font-family: 'JetBrains Mono', monospace;
            font-size: 14px; /* 字体稍微加大一点也显得更亮 */
        }
        
        QLineEdit:focus { 
            border: 1px solid #89b4fa; 
            background-color: #45475a; 
        }
    )");

    layout->addWidget(label);
    layout->addWidget(L_lineEdit);
}



/**
- 获取 行号
*/
int LosGotoLinePopupUi::getLineNumber() const
{
    return L_lineEdit->text().toInt();
}



/**
- 获取 输入框
*/
QLineEdit *LosGotoLinePopupUi::getLineEdit() const
{
    return L_lineEdit;
}

} // namespace LosView
