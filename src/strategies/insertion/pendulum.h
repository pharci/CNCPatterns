#pragma once

#include "strategies/insertion/InsertionBehavior.h"

class PendulumInsertion : public InsertionBehavior {
  private:
    double alpha;
    QString apply() override;

  public:
    PendulumInsertion(double alpha = 0) : alpha(alpha) {}
};