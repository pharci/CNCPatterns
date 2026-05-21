#pragma once
#include "core/generators/ProgramGenerator.h"

class ProgramDecorator : public ProgramGenerator {
  protected:
    ProgramGenerator *generator;

  public:
    ProgramDecorator(ProgramGenerator *g) : generator(g) {}
    virtual ~ProgramDecorator() { delete generator; }
};