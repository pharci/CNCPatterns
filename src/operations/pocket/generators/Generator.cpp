// Generator.cpp
#include "Generator.h"

namespace pocket {
Generator::Generator(const Params &params) : params(params) {}

QString Generator::run() {
    QString out;
    auto pocket = createPocket(params);
    auto insertion = createInsertion(params);
    auto machining = createMachining(params);
    int line = 10;
    out += QString("N%1 M6 T%2\n").arg(line).arg(params.ToolNumber);
    line += 10;
    out += QString("N%1 Z60\n").arg(line);
    line += 10;
    out += QString("N%1 ").arg(line) + pocket->apply(params);
    out += QString(" ") + insertion->apply(params);
    if (params.type == PocketType::Circular) { out += QString(" ") + machining->apply(params); }
    out += QString("\n");
    line += 10;
    out += QString("N%1 X%2 Y%3 Z%4\n").arg(line).arg(params.X).arg(params.Y).arg(params.Z);
    out += QString("M30");
    return out;
}

std::unique_ptr<InsertionBehavior> Generator::createInsertion(const Params &params) {
    switch (params.insertion) {
        case InsertionType::Spiral:
            return std::make_unique<SpiralInsertion>();
        case InsertionType::Pendulum:
            return std::make_unique<PendulumInsertion>();
        case InsertionType::Vertical:
        default:
            return std::make_unique<VerticalInsertion>();
    }
}
std::unique_ptr<MachiningBehavior> Generator::createMachining(const Params &params) {
    switch (params.machining) {
        case MachiningType::Planar:
            return std::make_unique<PlanarMachining>();
        case MachiningType::Helical:
        default:
            return std::make_unique<HelicalMachining>();
    }
}
std::unique_ptr<PocketBehavior> Generator::createPocket(const Params &params) {
    switch (params.type) {
        case PocketType::Circular:
            return std::make_unique<Circular>();
        case PocketType::Rectangular:
        default:
            return std::make_unique<Rectangular>();
    }
}
} // namespace pocket