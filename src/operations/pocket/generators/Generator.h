#pragma once
#include "core/generators/ProgramGenerator.h"
#include "operations/pocket/geometry/Circular.h"
#include "operations/pocket/geometry/Rectangular.h"
#include "operations/pocket/insertion/Pendulum.h"
#include "operations/pocket/insertion/Spiral.h"
#include "operations/pocket/insertion/Vertical.h"
#include "operations/pocket/machining/Helical.h"
#include "operations/pocket/machining/Planar.h"
#include "operations/pocket/models/Params.h"

namespace pocket {
class Generator : public ProgramGenerator {
  private:
    Params params;

  public:
    Generator(const Params &params);
    QString run() override;
    std::unique_ptr<InsertionBehavior> createInsertion(const Params &params);
    std::unique_ptr<MachiningBehavior> createMachining(const Params &params);
    std::unique_ptr<PocketBehavior> createPocket(const Params &params);
};
} // namespace pocket