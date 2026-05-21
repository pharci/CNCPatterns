#pragma once
#include "core/modules/OperationModule.h"

#include "Service.h"
#include "models/Data.h"
#include "widgets/ControlWidget.h"
#include "widgets/PreviewWidget.h"

namespace pocket {
class Module : public OperationModule {
  public:
    Data data;
    Service service;
    ControlWidget *controlWidget;
    PreviewWidget *previewWidget;
    QWidget *getControlWidget() override;
    QWidget *getPreviewWidget() override;
    Module();
};
} // namespace pocket
