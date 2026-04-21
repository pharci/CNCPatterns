#pragma once

#include "strategies/insertion/InsertionBehavior.h"

class SpiralInsertion : public InsertionBehavior {
  private:
    double R, H;
    QString apply() override;

  public:
    SpiralInsertion(double R = 0, double H = 0) : R(R), H(H) {}
};