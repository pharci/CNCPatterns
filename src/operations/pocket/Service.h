// Service.h
#pragma once
#include "common/pch.h"
#include "operations/pocket/models/Params.h"

namespace pocket {
class Service {
  public:
    QString generate(const Params &params);
};
} // namespace pocket