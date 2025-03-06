#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.showFullScreen();
    window.show();


    return app.exec();
}
