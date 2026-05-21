// Spiral.h
#pragma once
#include "InsertionBehavior.h"
namespace pocket {
class SpiralInsertion : public InsertionBehavior {
  private:
    QString apply(const Params &p) override;
};
} // namespace pocket