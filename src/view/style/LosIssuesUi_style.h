#pragma once
#include <QString>
namespace LosStyle {

inline const QString LosIssuesUi_getStyle() {
  return QString(R"(
        QTableWidget {
            background-color: #1E1E1E;
            color: #D4D4D4;
            border: none;
            gridline-color: #333333;
        }
        QTableWidget::item:selected {
            background-color: #062F4A;
            color: #FFFFFF;
        }
        QHeaderView::section {
            background-color: #252526;
            color: #CCCCCC;
            padding: 4px;
            border: 1px solid #333333;
        }
)");
}
} // namespace LosStyle