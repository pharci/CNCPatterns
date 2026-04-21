#include "strategies/insertion/pendulum.h"

QString PendulumInsertion::apply() {
    return "Pendulum Insertion: Alpha=" + QString::number(alpha);
}