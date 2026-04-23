#pragma once
#include "common/pch.h"

class PocketBehavior {
  public:
    virtual QString apply(const PocketParams &p) = 0;
    virtual ~PocketBehavior() = default;
};