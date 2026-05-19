// Subject.h
#pragma once
#include "common/PocketParams.h"
#include "observers/Observer.h"

class Subject {
  public:
    virtual void attach(Observer *observer) = 0;
    virtual void notify() = 0;
    virtual void setParams(const PocketParams &newParams) = 0;
};