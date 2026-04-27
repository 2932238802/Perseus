# Perseus AI Agent Skill

本文档用于为 AI 编码助手提供项目上下文。

## 项目概览

**Perseus** 是一个基于 Qt6 的 C++20 桌面 IDE，支持 C++、Rust、Python、CMake 项目的编辑、运行和 LSP 分析。

- **构建系统**: CMake + Ninja
- **编译器**: Clang-18
- **Qt 版本**: Qt6 (Widgets, Network, Concurrent, WebEngineWidgets, WebChannel)
****
---

## 目录结构

| 目录 | 命名空间 | 职责 |
|------|---------|------|
| `src/view/` | LosView | UI 组件和 `.ui` 表单 — 仅负责显示，不含业务逻辑 |
| `src/core/` | LosCore | 所有业务逻辑、管理器、运行器、LSP 客户端 |
| `src/models/` | LosModel | 数据结构 (`LosFilePath`, `LosFileNode`, `LosFileTreeModel`, `LosFileContext`) |
| `src/common/` | LosCommon | 常量、枚举、结构体、工具函数 |
| `resources/` | - | Qt 资源文件 (`.qrc`) |

---

## 关键单例

- **LosRouter** — 中央事件总线。所有跨组件通信通过 Qt 信号完成。永远不要直接从 view 调用 core 服务，应通过 `LosRouter` 信号转发。
- **LosState** — 线程安全键值存储 (`QHash<SG_STR, QVariant>`)，存储全局状态如当前项目路径 (`SG_STR::PROJECT_DIR`)。
- **LosLog** — 日志单例，提供宏: `INF(msg, cmp)`, `WAR(msg, cmp)`, `ERR(msg, cmp)`, `SUC(msg, cmp)`。
- **LosNet** — Qt 网络单例，用于插件下载。

---

## 核心子系统

### 运行器 (Runner)
- `LosRunManager` — 调度文件执行到正确的运行器
- `LosSingleCppRunner` — C++ 单文件运行
- `LosRustcRunner` — Rust 运行
- `LosPythonRunner` — Python 运行
- `LosCmakeRunner` — CMake 运行
- `LosScriptRunner` — 脚本运行

### LSP
- `LosLspManager` — 管理语言服务器 (Clangd, rust-analyzer, neocmakelsp)
- `LosLspClient` — LSP JSON-RPC 客户端
- 各语言实现: `LosLspClangd`, `LosLspRust`, `LosLspPython`, `LosLspCMake`

### 配置与工具链
- `LosConfigManager` — 项目类型检测和配置
- `LosToolChainManager` — 工具链验证

### 其他
- `LosShortcutManager` — 快捷键管理
- `LosTerminal` — 终端管理
- `LosFileSystem` — 文件系统操作
- `LosHighlighter` — 语法高亮
- `LosFormatManager` — 代码格式化

---

## UI 组件

- `LosEditorTabUi` — 标签页管理
- `LosEditorUi` — 代码编辑器 (`QPlainTextEdit` 子类)
- `LosLineNumberUi` — 行号显示
- `LosCompleterUi` — 自动补全
- `LosFileTreeUi` — 文件树
- `LosTerminalUi` — 终端
- `LosTerminalTabsUi` — 终端标签页
- `LosFloatingPanelUi` — 浮动面板
- `LosPluginDetailUi` — 插件详情

---

## 常用命令

### 构建运行
```bash
./re-build.sh   # 完整重建 (删除 _build，重新配置，构建，运行)
./build.sh      # 增量构建 + 运行
./gdb-build.sh  # Debug 构建
./clean.sh      # 仅删除 _build
./_build/Perseus  # 直接运行
```

### 测试
```bash
cd _build && ctest --output-on-failure       # 运行所有测试
cd _build && ctest -R <TestName> -V          # 运行单个测试 (正则匹配， verbose)
cmake --build _build --target LosTest        # 仅构建测试目标
```

### 格式化
```bash
clang-format -i path/to/file.cpp path/to/file.h
```

### 代码统计
```bash
./test/loc.sh   # 统计各模块有效代码行数
```

---

## 命名规范

| 实体 | 规范 | 示例 |
|------|------|------|
| 类 / 结构体 | `PascalCase` | `LosRunManager` |
| 方法 / 函数 | `camelCase` | `initConnect` |
| 普通成员变量 | `L_` 前缀 | `L_timer`, `L_dirty` |
| 服务对象成员 | `LOS_` 前缀 | `LOS_runMgr`, `LOS_tabUi` |
| 常量 / 宏 | `UPPER_SNAKE_CASE` | `MAX_RETRIES` |

---

## 格式化规则 (`.clang-format`)

- 基础风格: LLVM
- 列宽限制: 120
- 缩进: 4 空格，禁止 Tab
- 大括号风格: Allman (左大括号独立一行)
- 指针对齐: 右侧 (`Type *ptr`)
- Include 排序: 按字母顺序

### Include 顺序
1. 对应头文件 (`"Foo.h"` 放在 `Foo.cpp` 最前)
2. 本地项目头文件 (`"core/..."`, `"models/..."`)
3. Qt 头文件 (`<QString>`)
4. 标准 C++ 头文件 (`<memory>`)

优先在 `.h` 文件中使用前向声明，在 `.cpp` 中完整包含。

---

## 内存管理

- `QObject` 派生类型: 传入 `this` 作为父对象 — Qt 对象树自动清理
- 非 `QObject` 类型: 使用 `std::unique_ptr` / `std::shared_ptr`
- 避免使用 raw `new`/`delete`，除非立即移交给 Qt 父对象或智能指针

---

## 错误处理

- 使用早期返回避免嵌套；用 `qWarning()` / `ERR()` 守卫
- 优先使用 `bool` / `std::optional` 返回值，而非异常（Qt 事件循环与异常不兼容）
- 永远不要假设网络调用成功；连接到 `errorOccurred` 或 `finished` 信号

---

## 工作流程

1. **理解代码结构** — 修改前先阅读相关模块的代码
2. **遵循架构分离** — 业务逻辑放在 `core/`，UI 逻辑放在 `view/`
3. **跨组件通信** — 通过 `LosRouter` 信号/槽，不直接耦合
4. **格式化** — 提交前运行 `clang-format`
5. **构建测试** — 任何修改后执行 `./build.sh` 验证

---

## 开发约定

- 不要在 UI 类中放置业务逻辑
- 信号发射使用 `emit`，槽函数使用 `Q_SLOT`
- 重度操作（网络、文件 I/O）需异步执行，避免阻塞主 GUI 线程
- 永远不要提交硬编码的 secrets 或 keys