#pragma once

#include "strategies/machining/MachiningBehavior.h"

class HelicalMachining : public MachiningBehavior {
  private:
    QString apply() override;

  public:
    HelicalMachining() {}
};