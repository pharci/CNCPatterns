// App.cpp
#include "App.h"

App::App(QWidget *parent) : QMainWindow(parent) {
    QWidget *main = new QWidget(this);
    setCentralWidget(main);

    QHBoxLayout *layout = new QHBoxLayout(main);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    previewWidget = new PreviewWidget(&pocketService, this);
    pocketWidget = new PocketWidget(&pocketService, &pocketData, this);

    pocketData.attach(previewWidget);

    layout->addWidget(pocketWidget);
    layout->addWidget(previewWidget);
}

App::~App() {}