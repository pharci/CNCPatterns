// MachiningBehavior.h
#pragma once
#include "common/pch.h"

class MachiningBehavior {
  public:
    virtual QString apply(const PocketParams &p) = 0;
    virtual ~MachiningBehavior() = default;
};