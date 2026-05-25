// pocket/Module.h
#pragma once
#include "Service.h"
#include "core/modules/OperationModule.h"
#include "core/widgets/PreviewWidget.h"
#include "models/Data.h"
#include "observers/PreviewObserver.h"
#include "widgets/ControlWidget.h"

namespace pocket {
class Module : public OperationModule {
  public:
    Data data;
    Service service;
    ControlWidget *controlWidget;
    PreviewWidget *previewWidget;
    PreviewObserver *previewObserver;
    QWidget *getControlWidget() override;
    QWidget *getPreviewWidget() override;
    QString generate() override;
    Module();
};
} // namespace pocket