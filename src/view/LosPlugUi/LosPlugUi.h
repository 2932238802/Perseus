#pragma once
#include <QWidget>

namespace Ui {
class LosPlugUi;
}

namespace LosView {

class LosPlugUi : public QWidget {
    Q_OBJECT

public:
    explicit LosPlugUi(QWidget *parent = nullptr);
    ~LosPlugUi();

private:
    Ui::LosPlugUi *ui;
};

} // namespace LosView
