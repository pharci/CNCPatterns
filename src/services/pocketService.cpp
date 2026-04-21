#include "pocketService.h"
#include "strategies/insertion/pendulum.h"
#include "strategies/insertion/spiral.h"
#include "strategies/insertion/vertical.h"
#include "strategies/machining/helical.h"
#include "strategies/machining/planar.h"

QString PocketService::generate(const PocketParams &p) {
    QString out;

    out += "=== Pocket Cycle ===\n\n";

    out += QString("Type      : %1\n")
               .arg(p.type == PocketType::Circular
                        ? "Circular"
                        : "Rectangular");

    out += QString("Center X  : %1\n").arg(p.x);
    out += QString("Center Y  : %1\n").arg(p.y);
    out += QString("Depth     : %1\n").arg(p.depth);

    if (p.type == PocketType::Circular) {
        out += QString("Radius    : %1\n").arg(p.radius);
    } else {
        out += QString("Length    : %1\n").arg(p.length);
        out += QString("Width     : %1\n").arg(p.width);
    }

    auto insertion = createInsertion(p);
    out += insertion->apply();
    out += "\n";

    if (p.type == PocketType::Circular) {
        auto machining = createMachining(p);
        out += machining->apply();
        out += "\n";
    }

    return out;
}

std::unique_ptr<InsertionBehavior>
PocketService::createInsertion(const PocketParams &p) {
    switch (p.insertion) {
        case InsertionType::Spiral:
            return std::make_unique<SpiralInsertion>(
                p.insertionR,
                p.insertionH);

        case InsertionType::Pendulum:
            return std::make_unique<PendulumInsertion>(
                p.insertionAngle);

        case InsertionType::Vertical:
        default:
            return std::make_unique<VerticalInsertion>();
    }
}

std::unique_ptr<MachiningBehavior>
PocketService::createMachining(const PocketParams &p) {
    switch (p.machining) {
        case CircularMachining::Planar:
            return std::make_unique<PlanarMachining>();

        case CircularMachining::Helical:
        default:
            return std::make_unique<HelicalMachining>();
    }
}