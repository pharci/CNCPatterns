// Spiral.cpp
#include "Spiral.h"
namespace pocket {
QString SpiralInsertion::apply(const Params &p) {
    return QString("Q14=%1 R=%2 H=%3").arg((int) p.insertion).arg(p.insertionR).arg(p.insertionH);
}
} // namespace pocket