// PocketBehavior.h
#pragma once
#include "common/pch.h"
#include "operations/pocket/models/Params.h"

namespace pocket {
class PocketBehavior {
  public:
    virtual QString apply(const Params &p) = 0;
    virtual ~PocketBehavior() = default;
};
} // namespace pocket