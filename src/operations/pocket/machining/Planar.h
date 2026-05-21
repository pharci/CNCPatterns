// Planar.h
#pragma once
#include "MachiningBehavior.h"
namespace pocket {
class PlanarMachining : public MachiningBehavior {
  private:
    QString apply(const Params &p) override;
};
} // namespace pocket