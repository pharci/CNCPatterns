// App.h
#pragma once
#include "core/modules/OperationModule.h"

class App : public QMainWindow {
    Q_OBJECT
  public:
    App(QWidget *parent = nullptr);
    std::unique_ptr<OperationModule> currentModule;
    ~App();

  private:
    QHBoxLayout *layout;
    void setModule(std::unique_ptr<OperationModule> module);
    void loadPocketModule();
    void loadDrillingModule();
};