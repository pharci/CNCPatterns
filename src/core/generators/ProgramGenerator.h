#pragma once
class ProgramGenerator {
  public:
    virtual QString run() = 0;
    virtual ~ProgramGenerator() = default;
};