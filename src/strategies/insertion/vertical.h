#pragma once

#include "strategies/insertion/InsertionBehavior.h"

class VerticalInsertion : public InsertionBehavior {
  private:
    QString apply(const PocketParams &p) override;

  public:
    VerticalInsertion() {}
};