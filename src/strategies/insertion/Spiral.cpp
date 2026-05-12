// Spiral.cpp
#include "strategies/insertion/Spiral.h"

QString SpiralInsertion::apply(const PocketParams &p) {
    return QString("Q14=%1 R=%2 H=%3").arg((int) p.insertion).arg(p.insertionR).arg(p.insertionH);
}