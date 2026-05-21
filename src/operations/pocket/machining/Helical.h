// Helical.h
#pragma once
#include "MachiningBehavior.h"
namespace pocket {
class HelicalMachining : public MachiningBehavior {
  private:
    QString apply(const Params &p) override;
};
} // namespace pocket