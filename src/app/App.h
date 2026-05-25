// App.h
#pragma once
#include "core/modules/OperationModule.h"

class App : public QMainWindow {
    Q_OBJECT
  public:
    App(QWidget *parent = nullptr);
    ~App();

  private:
    std::unique_ptr<OperationModule> currentModule = nullptr;
    QWidget *ControlWidget = nullptr;
    QWidget *PreviewWidget = nullptr;
    QHBoxLayout *mainLayout;

    void showModule(std::unique_ptr<OperationModule> module);
    void openPocketModule();
    void openDrillingModule();
    void createToolbar();
};