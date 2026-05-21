// MachiningBehavior.h
#pragma once
#include "common/pch.h"
#include "operations/pocket/models/Params.h"
namespace pocket {
class MachiningBehavior {
  public:
    virtual QString apply(const Params &p) = 0;
    virtual ~MachiningBehavior() = default;
};
} // namespace pocket