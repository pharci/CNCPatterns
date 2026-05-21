// Service.cpp
#include "Service.h"

#include "core/decorators/SafetyLineDecorator.h"
#include "core/decorators/WorkpieceDecorator.h"
#include "core/generators/ProgramGenerator.h"
#include "generators/Generator.h"

namespace drilling {
QString Service::generate(const Params &p) {
    ProgramGenerator *generator = new Generator(p);
    generator = new WorkpieceDecorator(generator);
    generator = new SafetyLineDecorator(generator);
    QString result = generator->run();
    delete generator;
    return result;
}
} // namespace drilling