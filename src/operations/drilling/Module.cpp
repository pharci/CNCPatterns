#include "operations/drilling/Module.h"
namespace drilling {
Module::Module() {
    previewWidget = new PreviewWidget(&service);
    controlWidget = new ControlWidget(&data);
    data.attach(previewWidget);
}

QWidget *Module::getControlWidget() { return controlWidget; }

QWidget *Module::getPreviewWidget() { return previewWidget; }
} // namespace drilling