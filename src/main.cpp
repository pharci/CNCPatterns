#include "app/app.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    App w;
    w.setWindowTitle("CNCPatterns");
    w.resize(400, 600);
    w.show();
    return a.exec();
}