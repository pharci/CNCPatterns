#pragma once
#include "common/pch.h"

class InsertionBehavior {
  public:
    virtual QString apply() = 0;
    virtual ~InsertionBehavior() = default;
};