// Vertical.h
#pragma once
#include "InsertionBehavior.h"
namespace pocket {
class VerticalInsertion : public InsertionBehavior {
  private:
    QString apply(const Params &p) override;
};
} // namespace pocket