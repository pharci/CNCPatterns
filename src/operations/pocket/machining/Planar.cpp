// Planar.cpp
#include "Planar.h"
namespace pocket {
QString PlanarMachining::apply(const Params &p) {
    return QString("Q15=%1").arg((int) p.machining);
}
} // namespace pocket