// PreviewWidget.cpp
#include "PreviewWidget.h"

PreviewWidget::PreviewWidget(PocketService *pocketService, QWidget *parent) : QWidget(parent), pocketService(pocketService) {
    previewEdit = new QPlainTextEdit(this);
    previewEdit->setReadOnly(true);
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Preview GCode", this));
    layout->addWidget(previewEdit);
}

void PreviewWidget::update(const PocketParams &params) {
    QString gcode = pocketService->generate(params);
    previewEdit->setPlainText(gcode);
}