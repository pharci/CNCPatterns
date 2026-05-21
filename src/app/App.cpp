// App.cpp
#include "App.h"
#include "operations/drilling/Module.h"
#include "operations/pocket/Module.h"

App::App(QWidget *parent) : QMainWindow(parent) {
    QWidget *main = new QWidget(this);
    setCentralWidget(main);

    layout = new QHBoxLayout(main);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    currentModule = std::make_unique<pocket::Module>();
    layout->addWidget(currentModule->getControlWidget());
    layout->addWidget(currentModule->getPreviewWidget());

    QMenu *operationsMenu = menuBar()->addMenu("Operations");
    QAction *pocketAction = operationsMenu->addAction("Pocket");
    QAction *drillingAction = operationsMenu->addAction("Drilling");

    connect(pocketAction, &QAction::triggered,
            this, &App::loadPocketModule);

    connect(drillingAction, &QAction::triggered,
            this, &App::loadDrillingModule);
}

App::~App() {}

void App::setModule(std::unique_ptr<OperationModule> module) {
    if (currentModule) {
        layout->removeWidget(currentModule->getControlWidget());
        layout->removeWidget(currentModule->getPreviewWidget());

        delete currentModule->getControlWidget();
        delete currentModule->getPreviewWidget();
    }

    currentModule = std::move(module);

    layout->addWidget(currentModule->getControlWidget());
    layout->addWidget(currentModule->getPreviewWidget());
}

void App::loadPocketModule() { setModule(std::make_unique<pocket::Module>()); }
void App::loadDrillingModule() { setModule(std::make_unique<drilling::Module>()); }