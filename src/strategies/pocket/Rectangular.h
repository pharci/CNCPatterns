// Rectangular.h
#pragma once
#include "strategies/pocket/PocketBehavior.h"

class Rectangular : public PocketBehavior {
  private:
    QString apply(const PocketParams &p) override;
};