// PeckCycle.cpp
#include "PeckCycle.h"

namespace drilling {

QString PeckCycle::apply(const Params &p) {

    return QString(
               "G83 X%1 Y%2 Z-%3 Q%4 F%5")
        .arg(p.x)
        .arg(p.y)
        .arg(p.depth)
        .arg(p.peckDepth)
        .arg(p.feed);
}

} // namespace drilling