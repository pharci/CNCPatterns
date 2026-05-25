// App.cpp
#include "App.h"
#include "operations/drilling/Module.h"
#include "operations/pocket/Module.h"

App::App(QWidget *parent) : QMainWindow(parent) {
    QWidget *main = new QWidget(this);
    setCentralWidget(main);
    mainLayout = new QHBoxLayout(main);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    createToolbar();
}

App::~App() {}

void App::showModule(std::unique_ptr<OperationModule> module) {
    if (ControlWidget) {
        mainLayout->removeWidget(ControlWidget);
        ControlWidget->hide();
    }
    if (PreviewWidget) {
        mainLayout->removeWidget(PreviewWidget);
        PreviewWidget->hide();
    }

    currentModule = std::move(module);

    ControlWidget = currentModule->getControlWidget();
    PreviewWidget = currentModule->getPreviewWidget();
    mainLayout->addWidget(ControlWidget);
    mainLayout->addWidget(PreviewWidget);
    ControlWidget->show();
    PreviewWidget->show();
}

void App::openPocketModule() {
    auto module = std::make_unique<pocket::Module>();
    showModule(std::move(module));
}
void App::openDrillingModule() {
    auto module = std::make_unique<drilling::Module>();
    showModule(std::move(module));
}

void App::createToolbar() {
    QMenu *operationsMenu = menuBar()->addMenu("Operations");
    QAction *pocketAction = operationsMenu->addAction("Pocket");
    QAction *drillingAction = operationsMenu->addAction("Drilling");
    connect(pocketAction, &QAction::triggered, this, &App::openPocketModule);
    connect(drillingAction, &QAction::triggered, this, &App::openDrillingModule);
}