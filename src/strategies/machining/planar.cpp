#include "strategies/machining/Planar.h"

QString PlanarMachining::apply(const PocketParams &p) {
    return QString("Q15=%1").arg((int) p.machining);
}