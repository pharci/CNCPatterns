#pragma once

#include "strategies/pocket/PocketBehavior.h"

class Circular : public PocketBehavior {
  private:
    QString apply(const PocketParams &p) override;

  public:
    Circular() {}
};