// SimpleCycle.cpp
#include "Cycle.h"

namespace drilling {

class SimpleCycle : public Cycle {
  public:
    QString apply(const Params &p) override;
};

} // namespace drilling