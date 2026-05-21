#include "SafetyLineDecorator.h"

SafetyLineDecorator::SafetyLineDecorator(ProgramGenerator *g) : ProgramDecorator(g) {}

QString SafetyLineDecorator::run() {
    QString safety = "G17 G40 G49 G80 G90\n";
    return safety + generator->run();
}