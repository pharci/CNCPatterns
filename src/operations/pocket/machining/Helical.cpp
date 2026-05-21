// Helical.cpp
#include "Helical.h"
namespace pocket {
QString HelicalMachining::apply(const Params &p) {
    return QString("Q15=%1").arg((int) p.machining);
}
} // namespace pocket