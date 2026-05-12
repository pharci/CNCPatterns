// Vertical.cpp
#include "strategies/insertion/Vertical.h"

QString VerticalInsertion::apply(const PocketParams &p) {
    return QString("Q14=%1").arg((int) p.insertion);
}