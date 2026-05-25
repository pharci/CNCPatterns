#include "PreviewObserver.h"

namespace pocket {

PreviewObserver::PreviewObserver(PreviewWidget *preview, Service *service)
    : preview(preview), service(service) {}

void PreviewObserver::update(const Params &params) { preview->setText(service->generate(params)); }

} // namespace pocket
