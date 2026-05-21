// Rectangular.h
#pragma once
#include "PocketBehavior.h"

namespace pocket {
class Rectangular : public PocketBehavior {
  private:
    QString apply(const Params &p) override;
};
} // namespace pocket