sed -i '/QApplication a(argc, argv);/i \    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);\n' src/main.cpp
