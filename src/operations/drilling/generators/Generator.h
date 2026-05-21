#pragma once
#include "core/generators/ProgramGenerator.h"
#include "operations/drilling/cycles/Cycle.h"
#include "operations/drilling/models/Params.h"

namespace drilling {
class Generator : public ProgramGenerator {
  private:
    Params params;

  public:
    Generator(const Params &params);
    QString run() override;
    std::unique_ptr<Cycle> createCycle(const Params &params);
};
} // namespace drilling