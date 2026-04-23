#pragma once

#include "strategies/insertion/InsertionBehavior.h"

class PendulumInsertion : public InsertionBehavior {
  private:
    QString apply(const PocketParams &p) override;

  public:
    PendulumInsertion() {}
};