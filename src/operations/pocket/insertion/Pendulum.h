// Pendulum.h
#pragma once
#include "InsertionBehavior.h"
namespace pocket {
class PendulumInsertion : public InsertionBehavior {
  private:
    QString apply(const Params &p) override;
};
} // namespace pocket