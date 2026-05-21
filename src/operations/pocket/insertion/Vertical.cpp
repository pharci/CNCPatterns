// Vertical.cpp
#include "Vertical.h"
namespace pocket {
QString VerticalInsertion::apply(const Params &p) {
    return QString("Q14=%1").arg((int) p.insertion);
}
} // namespace pocket