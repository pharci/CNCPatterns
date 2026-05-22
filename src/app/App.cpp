// App.cpp
#include "App.h"
#include "operations/drilling/Module.h"
#include "operations/pocket/Module.h"

App::App(QWidget *parent) : QMainWindow(parent) {
    QWidget *main = new QWidget(this);
    setCentralWidget(main);

    root = new QHBoxLayout(main);
    root->setContentsMargins(0, 0, 0, 0);
    root->setSpacing(0);

    QMenu *operationsMenu = menuBar()->addMenu("Operations");
    QAction *pocketAction = operationsMenu->addAction("Pocket");
    QAction *drillingAction = operationsMenu->addAction("Drilling");

    connect(pocketAction, &QAction::triggered, this, &App::loadPocketModule);
    connect(drillingAction, &QAction::triggered, this, &App::loadDrillingModule);

    setModule(std::make_unique<pocket::Module>());
}

App::~App() {}

void App::setModule(std::unique_ptr<OperationModule> module) {
    if (ControlWidget) {
        root->removeWidget(ControlWidget);
        ControlWidget->deleteLater();
    }

    if (PreviewWidget) {
        root->removeWidget(PreviewWidget);
        PreviewWidget->deleteLater();
    }

    currentModule = std::move(module);

    ControlWidget = currentModule->getControlWidget();
    PreviewWidget = currentModule->getPreviewWidget();

    root->addWidget(ControlWidget);
    root->addWidget(PreviewWidget);
}

void App::loadPocketModule() { setModule(std::make_unique<pocket::Module>()); }
void App::loadDrillingModule() { setModule(std::make_unique<drilling::Module>()); }