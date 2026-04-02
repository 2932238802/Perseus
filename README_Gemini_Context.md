你好！我是项目的开发者。在接下来的对话中，请你严格遵循以下关于本项目（Perseus）的架构、技术栈以及代码规范约束。
## 1. 技术栈 (Tech Stack)
- **语言**: C++20 (启用 `CMAKE_CXX_STANDARD_REQUIRED`)
- **构建系统**: CMake (最低版本 3.18)
- **核心框架**: Qt 5 或 Qt 6 兼容
- **使用的 Qt 模块**: `Widgets`, `Network`, `Concurrent`, `WebEngineWidgets`, `WebChannel`。
## 2. 目录架构 (Architecture & Structure)
本项目严格遵守“关注点分离”原则，请绝对不要把业务逻辑写在 UI 类中。
- `src/view/`: UI 组件、Qt Designer 表单 (`.ui`) 以及纯视图层的渲染和交互逻辑。
- `src/core/`: 核心业务逻辑、网络请求管理、应用编排（Backend logic）。
- `src/models/`: 数据结构定义、数据模型（Data Transfer Objects）。
- `src/common/`: 共享工具类、全局常量、宏和辅助函数。
- `resources/` & `resources.qrc`: Qt 资源文件存放处。
## 3. 代码规范 (Coding Standards)
本项目使用 `.clang-format` 进行严格的格式化控制：
- **风格基准**: LLVM (120 字符行宽)。
- **缩进**: 4 个空格 (严禁使用 Tab)。
- **大括号风格**: `Allman` 风格（大括号必须另起一行）。
- **指针与引用**: 靠右对齐 (例：`QString *str` 而不是 `QString* str`)。
### 命名规范：
- **类/结构体**: `PascalCase` (如：`NetworkManager`)。
- **函数/方法**: `camelCase` (如：`fetchData()`)。
- **局部变量**: `camelCase` (如：`itemCount`)。
- **成员变量**: 必须带有 `m_` 前缀 (如：`m_apiClient`)。
- **常量/宏**: `UPPER_SNAKE_CASE` (如：`MAX_TIMEOUT`)。
## 4. 内存管理与最佳实践
- **Qt 对象树**: 对于所有继承自 `QObject` 的类，必须在构造函数中传递 `parent` 指针以保证内存自动回收。
- **智能指针**: 对于非 `QObject` 的标准 C++ 对象，强制使用 `std::unique_ptr` 或 `std::shared_ptr`，严禁直接使用裸指针进行 `new`/`delete`。
- **信号与槽 (Signals and Slots)**: 模块间通信（如 `core` 通知 `view` 数据已更新）必须使用 Qt 的信号与槽机制，实现解耦。
- **异步处理**: 任何耗时操作（网络请求、文件 I/O）必须在独立线程或使用 Qt 异步机制进行，绝不能阻塞主 GUI 线程。
- **异常处理**: 优先返回错误码、布尔值或使用 `std::optional`，避免在 Qt 事件循环中抛出标准 C++ 异常。通过连接 `QNetworkReply` 的 `errorOccurred` 信号处理网络错误。
## 5. 编译与运行指令
如果你需要协助我编译、运行或测试代码，请使用以下脚本/指令：
- **生成/更新构建**: `cmake -B _build -DCMAKE_BUILD_TYPE=Release`
- **编译**: `./build.sh` (或 `cmake --build _build --config Release`)
- **清理并重新编译**: `./re-build.sh`
- **运行**: `make run` (或 `./_build/Perseus`)
## 你的任务说明
在提供任何代码修改之前：
1. 思考代码应该放在哪个层级（View 还是 Core？）。
2. 使用给定的命名规范和大括号风格生成代码。
3. 确保包含必要的头文件，并且遵循正确的引入顺序（优先局部头文件，其次 Qt 头文件，最后标准库）。