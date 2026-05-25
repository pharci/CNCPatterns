// PreviewWidget.cpp
#include "PreviewWidget.h"
PreviewWidget::PreviewWidget(QWidget *parent) : QWidget(parent) {
    setMinimumWidth(200);
    previewEdit = new QPlainTextEdit(this);
    previewEdit->setReadOnly(true);
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(previewEdit);
}

void PreviewWidget::setText(const QString &text) { previewEdit->setPlainText(text); }