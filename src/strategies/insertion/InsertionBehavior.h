// InsertionBehavior.h
#pragma once
#include "common/pch.h"

class InsertionBehavior {
  public:
    virtual QString apply(const PocketParams &p) = 0;
    virtual ~InsertionBehavior() = default;
};