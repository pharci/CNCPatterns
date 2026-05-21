// PreviewWidget.cpp
#include "PreviewWidget.h"
namespace drilling {
PreviewWidget::PreviewWidget(Service *drillingService, QWidget *parent)
    : QWidget(parent), drillingService(drillingService) {
    previewEdit = new QPlainTextEdit(this);
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Preview GCode", this));
    layout->addWidget(previewEdit);
}

void PreviewWidget::update(const Params &params) {
    QString gcode = drillingService->generate(params);
    previewEdit->setPlainText(gcode);
}
} // namespace drilling