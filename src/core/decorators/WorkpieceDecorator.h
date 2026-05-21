// WorkpieceDecorator.h
#pragma once
#include "ProgramDecorator.h"

class WorkpieceDecorator : public ProgramDecorator {
  public:
    QString run() override;
    WorkpieceDecorator(ProgramGenerator *g);
};