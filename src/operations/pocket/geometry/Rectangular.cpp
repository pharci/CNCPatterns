// Rectangular.cpp
#include "Rectangular.h"

namespace pocket {
QString Rectangular::apply(const Params &p) {
    return QString("G387 Q3=%1 Q5=%2 Q6=%3 Q7=%4 Q8=%5")
        .arg(p.Feed)
        .arg(p.Z1)
        .arg(p.DZ)
        .arg(p.length)
        .arg(p.width);
}
} // namespace pocket