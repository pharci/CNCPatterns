// Subject.h
#pragma once
#include "Observer.h"

template <typename T>
class Subject {
  public:
    virtual void attach(Observer<T> *observer) = 0;
    virtual void notify() = 0;
    virtual void setParams(const T &newParams) = 0;
    virtual ~Subject() = default;
};