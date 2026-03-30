#pragma once
#include <QString>

namespace LosStyle
{

inline const QString perseus_getStyle()
{
    return QString(R"(

        QMainWindow {
            background-color: #1e1e2e; 
        }
        
        * {
            outline: none;  
        }

        QToolTip {
            background-color: #313244;  
            color: #cdd6f4;             
            border: 1px solid #45475a;  
            border-radius: 4px;
            padding: 4px 8px;
            font-family: "Microsoft YaHei", sans-serif;
            font-size: 0.9em;
        }

        #toolbar_widget {
            background-color: #181825; 
            border-bottom: 1px solid #313244;
        }

        #icon_btn, #files_btn, #run_singleFile_btn, #setting_btn{
            border: 1px solid transparent; 
            background-color: rgba(255, 255, 255, 0.01);
            color: #cdd6f4; 
            border-radius: 4px;
            padding: 4px 12px; 
            font-size: 16px;
            font-family: "Microsoft YaHei", sans-serif;
        }
        
        #icon_btn {
            font-weight: bold;
            color: #89b4fa; 
            padding: 4px 0px;   
            min-width: 32px;     
            text-align: center;  
            font-size: 1.15em; 
        }

        #icon_btn:hover, #files_btn:hover, #run_singleFile_btn:hover, #setting_btn:hover {
            background-color: #313244;
            border: 1px solid #313244;
            color: #ffffff; 
        }

        #icon_btn:pressed, #files_btn:pressed, #run_singleFile_btn:pressed, #setting_btn:pressed{
            background-color: #45475a;
            border: 1px solid #45475a;
        }

        #project_btn {
            background-color: transparent;
            color: #6c7086; 
            border: none;
            padding: 6px 16px;
            font-size: 14px;
            font-family: "Microsoft YaHei", sans-serif;
            spacing: 8px; 
        }

        #project_btn:hover {
            color: #cdd6f4;  
        }

        #project_btn:checked {
            color: #89b4fa;  
            font-weight: bold;
        }

        #project_btn::indicator {
            width: 16px;
            height: 16px;
            border-radius: 8px;
            border: 2px solid #45475a; 
            background-color: transparent;
        }

        #project_btn::indicator:hover {
            border-color: #6c7086; 
        }

        #project_btn::indicator:checked {
            border-color: #89b4fa; 
            background-color: #89b4fa; 
            background: qradialgradient(
                cx: 0.5, cy: 0.5, radius: 0.5,
                fx: 0.5, fy: 0.5,
                stop: 0 #cdd6f4,  
                stop: 0.4 #89b4fa,  
                stop: 1 #89b4fa      
            );
        }

        #project_btn::indicator:checked:hover {
            background: qradialgradient(
                cx: 0.5, cy: 0.5, radius: 0.5,
                fx: 0.5, fy: 0.5,
                stop: 0 #ffffff,      
                stop: 0.4 #74c7ec,   
                stop: 1 #74c7ec
            );
        }

        QSplitter::handle {
            background-color: #1e1e2e;
            margin: 1px;
        }
            
        QSplitter::handle:horizontal:hover, QSplitter::handle:vertical:hover {
            background-color: #89b4fa;
        }

        QTreeView {
            background-color: #181825;
            color: #bac2de; 
            border: none;
            show-decoration-selected: 1; 
        }
        QTreeView::item {
            padding: 4px 0px;
            border-radius: 4px;
            margin: 0px 4px; 
        }
        QTreeView::item:hover {
            background-color: #313244;
            color: #cdd6f4;
        }
        QTreeView::item:selected {
            background-color: #45475a;
            color: #89b4fa; 
            font-weight: bold;
        }
        QTreeView::branch {
            background-color: transparent;
        }

        #editor_tabwidget::pane {
            border: none;
            background-color: #1e1e2e;
        }
        #editor_tabwidget QTabBar {
            background-color: #181825;
        }
        #editor_tabwidget QTabBar::tab {
            background-color: #181825;
            color: #6c7086;
            padding: 8px 16px;
            border: none;
            border-right: 1px solid #1e1e2e; 
            min-width: 90px;
        }
        #editor_tabwidget QTabBar::tab:selected {
            background-color: #1e1e2e;
            color: #89b4fa; 
            border-top: 2px solid #89b4fa; 
        }
        #editor_tabwidget QTabBar::tab:hover:!selected {
            background-color: #313244;
            color: #cdd6f4;
        }
        #editor_tabwidget QTabBar::close-button {
            subcontrol-position: right;
            margin-right: 2px;
        }
        #editor_tabwidget QTabBar::close-button:hover {
            background-color: #f38ba8; 
            border-radius: 2px;
        }

        #bottom_tabwidget::pane {
            border-top: 1px solid #313244; 
            background-color: #181825;
        }
        #bottom_tabwidget QTabBar {
            background-color: #1e1e2e;
        }
        #bottom_tabwidget QTabBar::tab {
            background-color: transparent;
            color: #6c7086;
            padding: 4px 16px 2px 16px; 
            border: none;
            border-bottom: 2px solid transparent;
            font-size: 0.9em;
            text-transform: uppercase; 
        }
        #bottom_tabwidget QTabBar::tab:selected {
            color: #cdd6f4;
            border-bottom: 2px solid #89b4fa; 
        }
        #bottom_tabwidget QTabBar::tab:hover:!selected {
            color: #a6adc8;
        }

        QPlainTextEdit {
            background-color: #1e1e2e;
            color: #cdd6f4;
            border: none;
            font-family: "JetBrains Mono", "Consolas", monospace;
            font-size: 1.1em;
            selection-background-color: #45475a;
            selection-color: #cdd6f4;
            padding: 4px;
        }
        
        #output_plaintextedit {
            background-color: #181825;
        }

        QScrollBar:vertical {
            background-color: transparent;
            width: 12px;
            border: none;
            margin: 0px;
        }
        QScrollBar::handle:vertical {
            background-color: rgba(69, 71, 90, 0.6); 
            border-radius: 6px;
            min-height: 30px;
            margin: 2px; 
        }
        QScrollBar::handle:vertical:hover {
            background-color: rgba(88, 91, 112, 0.9);
        }
        QScrollBar:horizontal {
            background-color: transparent;
            height: 12px;
            border: none;
            margin: 0px;
        }
        QScrollBar::handle:horizontal {
            background-color: rgba(69, 71, 90, 0.6);
            border-radius: 6px;
            min-width: 30px;
            margin: 2px;
        }
        QScrollBar::handle:horizontal:hover {
            background-color: rgba(88, 91, 112, 0.9);
        }
        QScrollBar::add-line, QScrollBar::sub-line {
            height: 0px; width: 0px; 
        }
        QScrollBar::add-page, QScrollBar::sub-page {
            background-color: transparent; 
        }




        QDialog#LosSettingsUi {
            background-color: #1e1e2e;
        }

        #category_list {
            background-color: #181825;  /* 比主背景稍微深一点，制造层次感 */
            border: none;
            border-right: 1px solid #313244; /* 右侧分割线 */
            padding-top: 10px;
            font-family: "Microsoft YaHei", sans-serif;
            font-size: 14px;
            outline: none; 
        }

        #category_list::item {
            color: #bac2de;
            padding: 10px 15px;
            border-left: 3px solid transparent; 
        }

        #category_list::item:hover {
            background-color: #313244;
            color: #cdd6f4;
        }

        #category_list::item:selected {
            background-color: #1e1e2e; /* 选中时背景色和右侧主区域融为一体 */
            color: #89b4fa;            /* 选中的文字变成主题蓝 */
            font-weight: bold;
            border-left: 3px solid #89b4fa; /* 左侧蓝色高亮粗线条 */
        }

        #pages_stack {
            background-color: #1e1e2e;
            border: none;
        }

        #label_title_build {
            color: #cdd6f4;
            border-bottom: 1px solid #313244; /* 标题下方的华丽分割线 */
            padding-bottom: 5px;
            font-family: "Microsoft YaHei", sans-serif;
        }

        #label_cmake {
            color: #a6adc8;
            font-size: 14px;
            font-family: "Microsoft YaHei", sans-serif;
        }

        #edit_cmake_path {
            background-color: #11111b; /* 最深的底色，制造凹陷感 */
            color: #cdd6f4;
            border: 1px solid #313244;
            border-radius: 4px;
            padding: 6px 10px;
            font-family: "JetBrains Mono", "Consolas", monospace; /* 路径使用等宽字体更专业 */
            font-size: 13px;
        }
        #edit_cmake_path:hover {
            border: 1px solid #45475a;
        }
        #edit_cmake_path:focus {
            border: 1px solid #89b4fa; /* 获取焦点时，边框变成亮蓝色 */
            background-color: #181825;
        }

        #buttonBox QPushButton {
            background-color: #313244;
            color: #cdd6f4;
            border: 1px solid transparent;
            border-radius: 4px;
            padding: 6px 16px;
            min-width: 60px;
            font-family: "Microsoft YaHei", sans-serif;
            font-size: 13px;
        }
        #buttonBox QPushButton:hover {
            background-color: #45475a;
            color: #ffffff;
        }
        #buttonBox QPushButton:pressed {
            background-color: #585b70;
            border: 1px solid #89b4fa; /* 按下时给个蓝边反馈 */
        }

        #buttonBox QPushButton[text="OK"] {
            background-color: #89b4fa;
            color: #11111b;
            font-weight: bold;
        }
        #buttonBox QPushButton[text="OK"]:hover {
            background-color: #74c7ec; /* 悬停时稍微变亮 */
        }

    )");
}

} // namespace LosStyle
