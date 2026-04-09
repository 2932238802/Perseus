#pragma once

#include "common/constants/ConstantsClass.h"
#include "view/style/LosCommandUi_style.h"

#include <QGraphicsDropShadowEffect>
#include <QKeyEvent>
#include <QString>
#include <qdialog.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qtmetamacros.h>
#include <qwidget.h>

namespace LosView
{
    class LosCommandUi : public QDialog
    {
        Q_OBJECT

      public:
        explicit LosCommandUi(QWidget *parent = nullptr);
        ~LosCommandUi() = default;

      public:
        void regis(const QString &display, const QString &cmd);
        void showPalette();

      private: // init
        void initStyle();
        void initConnect();

      private slots:
        void onSearchTextChanged(const QString &text);
        void executeSelectedItem();
        
      protected slots:
        bool eventFilter(QObject *watched, QEvent *event) override;
        void focusOutEvent(QFocusEvent *event) override;
        bool event(QEvent *event) override;

      private:
        QLineEdit *L_searchBox;
        QListWidget *L_lists;
        QMap<QString, QString> L_commands;
    };
} // namespace LosView
