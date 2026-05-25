// pocket/Module.cpp
#include "operations/pocket/Module.h"
namespace pocket {
Module::Module() {
    previewWidget = new PreviewWidget();
    previewObserver = new PreviewObserver(previewWidget, &service);
    controlWidget = new ControlWidget(&data);
    data.attach(previewObserver);
}
QWidget *Module::getControlWidget() { return controlWidget; }
QWidget *Module::getPreviewWidget() { return previewWidget; }
QString Module::generate() { return service.generate(data.getParams()); }
} // namespace pocket