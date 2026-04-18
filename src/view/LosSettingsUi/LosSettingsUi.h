
#pragma once
#include "core/LosLog/LosLog.h"
#include "core/LosRouter/LosRouter.h"
#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <memory>
#include <qdialog.h>
#include <qdialogbuttonbox.h>
#include <qpushbutton.h>
#include <qtmetamacros.h>
#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class LosSettingsUi;
}
QT_END_NAMESPACE

namespace LosView
{
    class LosSettingsUi : public QDialog
    {
        Q_OBJECT
      public:
        explicit LosSettingsUi(QWidget *parent = nullptr);
        ~LosSettingsUi();

      private:
        void initStyle();
        void initConnect();

      private slots:
        void onSaveSettings();

      public slots:
        void onCMakeInstallBtnClicked();

      private:
        Ui::LosSettingsUi *ui;
    };
}; /* namespace LosView */