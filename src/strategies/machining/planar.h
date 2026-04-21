#pragma once

#include "strategies/machining/MachiningBehavior.h"

class PlanarMachining : public MachiningBehavior {
  private:
    QString apply() override;

  public:
    PlanarMachining() {}
};