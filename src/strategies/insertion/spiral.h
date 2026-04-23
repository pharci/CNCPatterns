// Spiral.h
#pragma once

#include "strategies/insertion/InsertionBehavior.h"

class SpiralInsertion : public InsertionBehavior {
  private:
    QString apply(const PocketParams &p) override;
};