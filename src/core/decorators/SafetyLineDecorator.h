// SafetyLineDecorator.h
#pragma once
#include "ProgramDecorator.h"

class SafetyLineDecorator : public ProgramDecorator {
  public:
    QString run() override;
    SafetyLineDecorator(ProgramGenerator *g);
};