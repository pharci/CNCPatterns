// PocketData.cpp
#include "PocketData.h"

void PocketData::attach(Observer *observer) {
    observers.push_back(observer);
}

void PocketData::notify() {
    for (auto *observer : observers)
        observer->update(params);
}

void PocketData::setParams(const PocketParams &newParams) {
    params = newParams;
    notify();
}