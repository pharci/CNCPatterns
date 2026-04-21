#pragma once
#include "common/data.h"
#include "strategies/insertion/InsertionBehavior.h"
#include "strategies/machining/MachiningBehavior.h"

class PocketService {
  private:
    std::unique_ptr<InsertionBehavior> insertionStrategy;
    std::unique_ptr<MachiningBehavior> machiningStrategy;

  public:
    std::unique_ptr<InsertionBehavior>
    createInsertion(const PocketParams &params);

    std::unique_ptr<MachiningBehavior>
    createMachining(const PocketParams &params);

    QString generate(const PocketParams &params);
};