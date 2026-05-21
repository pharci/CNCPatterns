// PeckCycle.cpp
#include "Cycle.h"

namespace drilling {

class PeckCycle : public Cycle {
  public:
    QString apply(const Params &p) override;
};

} // namespace drilling