// Cycle.h
#pragma once
#include "operations/drilling/models/Params.h"

namespace drilling {

class Cycle {
  public:
    virtual QString apply(const Params &p) = 0;
    virtual ~Cycle() = default;
};

} // namespace drilling