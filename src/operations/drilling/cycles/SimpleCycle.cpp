// SimpleCycle.cpp
#include "SimpleCycle.h"

namespace drilling {

QString SimpleCycle::apply(const Params &p) {

    return QString(
               "G81 X%1 Y%2 Z-%3 F%4")
        .arg(p.x)
        .arg(p.y)
        .arg(p.depth)
        .arg(p.feed);
}

} // namespace drilling