// Service.h
#pragma once
#include "common/pch.h"
#include "core/services/OperationService.h"
#include "operations/drilling/models/Params.h"

namespace drilling {

class Service : public OperationService<Params> {
  public:
    QString generate(const Params &params);
};

} // namespace drilling