// Circular.h
#pragma once

#include "PocketBehavior.h"

namespace pocket {
class Circular : public PocketBehavior {
  private:
    QString apply(const Params &p) override;
};
} // namespace pocket