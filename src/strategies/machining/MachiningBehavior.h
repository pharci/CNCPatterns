#pragma once
#include "common/pch.h"

class MachiningBehavior {
  public:
    virtual QString apply() = 0;
    virtual ~MachiningBehavior() = default;
};