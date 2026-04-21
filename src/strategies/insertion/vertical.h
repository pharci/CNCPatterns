#pragma once

#include "strategies/insertion/InsertionBehavior.h"

class VerticalInsertion : public InsertionBehavior {
  private:
    QString apply() override;

  public:
    VerticalInsertion() {}
};