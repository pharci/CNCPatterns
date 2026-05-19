// PocketData.h
#pragma once
#include "common/PocketParams.h"
#include "observers/Observer.h"
#include "subject/Subject.h"
#include <vector>

class PocketData : public Subject {
  private:
    PocketParams params;
    std::vector<Observer *> observers;

  public:
    void attach(Observer *observer);
    void notify();
    void setParams(const PocketParams &newParams);
};