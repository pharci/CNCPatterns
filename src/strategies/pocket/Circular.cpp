#include "strategies/pocket/Circular.h"

QString Circular::apply(const PocketParams &p) {
    return QString("G389 Q3=%1 Q5=%2 Q6=%3 Q7=%4")
        .arg(p.Feed)
        .arg(p.Z1)
        .arg(p.DZ)
        .arg(p.radius * 2);
}