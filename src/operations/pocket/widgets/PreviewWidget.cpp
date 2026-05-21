// PreviewWidget.cpp
#include "PreviewWidget.h"
namespace pocket {
PreviewWidget::PreviewWidget(Service *pocketService, QWidget *parent)
    : QWidget(parent), pocketService(pocketService) {
    previewEdit = new QPlainTextEdit(this);
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Preview GCode", this));
    layout->addWidget(previewEdit);
}

void PreviewWidget::update(const Params &params) {
    QString gcode = pocketService->generate(params);
    previewEdit->setPlainText(gcode);
}
} // namespace pocket