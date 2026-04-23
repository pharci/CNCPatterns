#include "strategies/insertion/Pendulum.h"
#include <qobject.h>

QString PendulumInsertion::apply(const PocketParams &p) {
    return QString("Q14=%1 a=%2").arg((int) p.insertion).arg(p.insertionAngle);
}