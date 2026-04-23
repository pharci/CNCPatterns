// Planar.h
#pragma once

#include "strategies/machining/MachiningBehavior.h"

class PlanarMachining : public MachiningBehavior {
  private:
    QString apply(const PocketParams &p) override;
};