// Service.h
#pragma once
#include "common/pch.h"
#include "core/services/OperationService.h"
#include "operations/pocket/models/Params.h"

namespace pocket {

class Service : public OperationService<Params> {
  public:
    QString generate(const Params &params);
};

} // namespace pocket