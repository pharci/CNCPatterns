// Data.h
#pragma once
#include "core/observers/Observer.h"
#include "core/observers/Subject.h"
#include "operations/pocket/models/Params.h"
#include <vector>
namespace pocket {
class Data : public Subject<Params> {
  private:
    Params params;
    std::vector<Observer<Params> *> observers;

  public:
    void attach(Observer<Params> *observer);
    void notify();
    void setParams(const Params &newParams);
    Params getParams();
};
} // namespace pocket