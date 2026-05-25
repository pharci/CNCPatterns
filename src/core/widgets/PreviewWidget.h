// PreviewWidget.h
#pragma once
#include "common/pch.h"

class PreviewWidget : public QWidget {
    Q_OBJECT

  public:
    explicit PreviewWidget(QWidget *parent = nullptr);
    void setText(const QString &text);

  private:
    QPlainTextEdit *previewEdit;
};