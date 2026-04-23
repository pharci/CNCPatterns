#include "strategies/machining/Helical.h"

QString HelicalMachining::apply(const PocketParams &p) {
    return QString("Q15=%1").arg((int) p.machining);
}