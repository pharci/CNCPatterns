// PreviewWidget.h
#pragma once
#include "core/observers/Observer.h"
#include "operations/pocket/Service.h"
#include "operations/pocket/models/Params.h"
namespace pocket {
class PreviewWidget : public QWidget, public Observer<Params> {
    Q_OBJECT
  public:
    PreviewWidget(Service *pocketService, QWidget *parent = nullptr);
    Service *pocketService;
    QPlainTextEdit *previewEdit;
    void update(const Params &params);
};
} // namespace pocket