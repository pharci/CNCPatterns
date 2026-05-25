// Data.cpp
#include "Data.h"

namespace drilling {
void Data::attach(Observer<Params> *observer) { observers.push_back(observer); }

void Data::notify() {
    for (auto *observer : observers)
        observer->update(params);
}

void Data::setParams(const Params &newParams) {
    params = newParams;
    notify();
}

Params Data::getParams() { return params; }
} // namespace drilling