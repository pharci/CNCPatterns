// Generator.cpp
#include "Generator.h"
#include "operations/drilling/cycles/PeckCycle.h"
#include "operations/drilling/cycles/SimpleCycle.h"

namespace drilling {
Generator::Generator(const Params &params) : params(params) {}

QString Generator::run() {
    QString out;
    auto cycle = createCycle(params);
    out += QString("T%1 M6\n").arg(params.toolNumber);
    out += QString("S%1 F%2\n").arg(params.spindleSpeed).arg(params.feed);
    out += QString("G0 X%1 Y%2 Z%3\n").arg(params.x).arg(params.y).arg(params.safeZ);
    out += cycle->apply(params);
    out += "\nM30";
    return out;
}

std::unique_ptr<Cycle> Generator::createCycle(const Params &params) {
    switch (params.cycle) {
        case CycleType::Peck:
            return std::make_unique<PeckCycle>();
        case CycleType::Simple:
        default:
            return std::make_unique<SimpleCycle>();
    }
}

} // namespace drilling