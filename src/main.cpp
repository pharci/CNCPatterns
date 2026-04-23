#include "app/App.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    App w;
    w.setWindowTitle("CNCPatterns");
    w.show();
    return a.exec();
}