// Params.h
#pragma once

namespace drilling {

enum class CycleType {
    Simple = 1,
    Peck = 2
};

struct Params {
    int toolNumber;

    double feed;
    double spindleSpeed;

    double x;
    double y;

    double safeZ;
    double depth;

    double peckDepth;

    double holeDiameter;

    CycleType cycle;
};

} // namespace drilling