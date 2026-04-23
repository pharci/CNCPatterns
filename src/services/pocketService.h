#pragma once
#include "common/pch.h"
#include "strategies/insertion/InsertionBehavior.h"
#include "strategies/machining/MachiningBehavior.h"
#include "strategies/pocket/PocketBehavior.h"

class PocketService {
  private:
    std::unique_ptr<InsertionBehavior> insertionStrategy;
    std::unique_ptr<MachiningBehavior> machiningStrategy;
    std::unique_ptr<PocketBehavior> pocketStrategy;

  public:
    std::unique_ptr<InsertionBehavior> createInsertion(const PocketParams &params);
    std::unique_ptr<MachiningBehavior> createMachining(const PocketParams &params);
    std::unique_ptr<PocketBehavior> createPocket(const PocketParams &params);

    QString generate(const PocketParams &params);
};