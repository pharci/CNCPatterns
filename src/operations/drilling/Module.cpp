#include "operations/drilling/Module.h"
namespace drilling {
Module::Module() {
    previewWidget = new PreviewWidget();
    previewObserver = new PreviewObserver(previewWidget, &service);
    controlWidget = new ControlWidget(&data);
    data.attach(previewObserver);
}

QWidget *Module::getControlWidget() { return controlWidget; }

QWidget *Module::getPreviewWidget() { return previewWidget; }

QString Module::generate() { return service.generate(data.getParams()); }

} // namespace drilling