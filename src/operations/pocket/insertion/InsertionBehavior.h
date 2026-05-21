// InsertionBehavior.h
#pragma once
#include "common/pch.h"
#include "operations/pocket/models/Params.h"

namespace pocket {
class InsertionBehavior {
  public:
    virtual QString apply(const Params &p) = 0;
    virtual ~InsertionBehavior() = default;
};
} // namespace pocket