// Pendulum.cpp
#include "Pendulum.h"

namespace pocket {
QString PendulumInsertion::apply(const Params &p) {
    return QString("Q14=%1 a=%2").arg((int) p.insertion).arg(p.insertionAngle);
}
} // namespace pocket