#pragma once
#include "core/observers/Observer.h"
#include "core/widgets/PreviewWidget.h"
#include "operations/pocket/Service.h"
#include "operations/pocket/models/Params.h"

namespace pocket {

class PreviewObserver : public Observer<Params> {
  public:
    PreviewObserver(PreviewWidget *preview, Service *service);
    void update(const Params &params) override;

  private:
    PreviewWidget *preview;
    Service *service;
};

} // namespace pocket