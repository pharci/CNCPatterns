#include "PocketService.h"

#include "strategies/insertion/Pendulum.h"
#include "strategies/insertion/Spiral.h"
#include "strategies/insertion/Vertical.h"

#include "strategies/machining/Helical.h"
#include "strategies/machining/Planar.h"

#include "strategies/pocket/Circular.h"
#include "strategies/pocket/Rectangular.h"
#include <qobject.h>

QString PocketService::generate(const PocketParams &p) {
    QString out;
    auto pocket = createPocket(p);
    auto insertion = createInsertion(p);
    auto machining = createMachining(p);

    int line = 10;

    out += QString("N%1 M6 T%2\n").arg(line).arg(p.ToolNumber);
    line += 10;

    out += QString("N%1 Z60\n").arg(line);
    line += 10;

    out += QString("N%1 ").arg(line) + pocket->apply(p);
    out += QString(" ") + insertion->apply(p);
    if (p.type == PocketType::Circular) { out += QString(" ") + machining->apply(p); }
    out += QString("\n");

    line += 10;
    out += QString("N%1 X%2 Y%3 Z%4\n").arg(line).arg(p.X).arg(p.Y).arg(p.Z);

    out += QString("M30");

    return out;
}

std::unique_ptr<InsertionBehavior>
PocketService::createInsertion(const PocketParams &p) {
    switch (p.insertion) {
        case InsertionType::Spiral:
            return std::make_unique<SpiralInsertion>();

        case InsertionType::Pendulum:
            return std::make_unique<PendulumInsertion>();

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

std::unique_ptr<PocketBehavior>
PocketService::createPocket(const PocketParams &p) {
    switch (p.type) {
        case PocketType::Circular:
            return std::make_unique<Circular>();
        case PocketType::Rectangular:
        default:
            return std::make_unique<Rectangular>();
    }
}