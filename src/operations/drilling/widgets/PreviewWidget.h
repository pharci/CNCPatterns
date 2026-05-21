// PreviewWidget.h
#pragma once
#include "core/observers/Observer.h"
#include "operations/drilling/Service.h"
#include "operations/drilling/models/Params.h"
namespace drilling {
class PreviewWidget : public QWidget, public Observer<Params> {
    Q_OBJECT
  public:
    PreviewWidget(Service *drillingService, QWidget *parent = nullptr);
    Service *drillingService;
    QPlainTextEdit *previewEdit;
    void update(const Params &params);
};
} // namespace drilling