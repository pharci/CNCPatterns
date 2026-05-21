#pragma once

class OperationModule {
  public:
    virtual QWidget *getControlWidget() = 0;
    virtual QWidget *getPreviewWidget() = 0;

    virtual ~OperationModule() = default;
};