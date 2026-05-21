#include "WorkpieceDecorator.h"

WorkpieceDecorator::WorkpieceDecorator(ProgramGenerator *g) : ProgramDecorator(g) {}

QString WorkpieceDecorator::run() {
    QString workpiece = "WORKPIECE(,\"\",,\"BOX\",112,0,-15,-80,0,0,165,100)\n";
    return workpiece + generator->run();
}