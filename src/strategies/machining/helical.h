#pragma once

#include "strategies/machining/MachiningBehavior.h"

class HelicalMachining : public MachiningBehavior {
  private:
    QString apply(const PocketParams &p) override;

  public:
    HelicalMachining() {}
};