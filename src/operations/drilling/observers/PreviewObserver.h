#pragma once
#include "core/observers/Observer.h"
#include "core/widgets/PreviewWidget.h"
#include "operations/drilling/Service.h"
#include "operations/drilling/models/Params.h"

namespace drilling {

class PreviewObserver : public Observer<Params> {
  public:
    PreviewObserver(PreviewWidget *preview, Service *service);
    void update(const Params &params) override;

  private:
    PreviewWidget *preview;
    Service *service;
};

} // namespace drilling