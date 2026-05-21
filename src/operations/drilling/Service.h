// Service.h
#pragma once
#include "common/pch.h"
#include "operations/drilling/models/Params.h"

namespace drilling {

class Service {
  public:
    QString generate(const Params &params);
};

} // namespace drilling