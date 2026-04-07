#include "view/LosPlugUi/LosPlugUi.h"
#include "ui_LosPlugUi.h"

namespace LosView
{

LosPlugUi::LosPlugUi(QWidget *parent) : QWidget(parent), ui(new Ui::LosPlugUi)
{
    ui->setupUi(this);

    // test
    QStringList mockPlugins = {"11\n22", "33\n44"};

    for (const auto &info : mockPlugins)
    {
        ui->extensionsList->addItem(info);
    }
}

LosPlugUi::~LosPlugUi()
{
    delete ui;
}

} // namespace LosView
