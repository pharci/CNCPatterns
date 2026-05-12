#pragma once
#include "common/PocketParams.h"
#include "observers/Observer.h"
#include "services/PocketService.h"

class PreviewWidget : public QWidget, public Observer {
    Q_OBJECT
  public:
    PreviewWidget(PocketService *pocketService, QWidget *parent = nullptr);
    PocketService *pocketService;
    QPlainTextEdit *previewEdit;
    void update(const PocketParams &params);
};