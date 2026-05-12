// Observer.h
#pragma once
class Observer {
  public:
    virtual void update(const PocketParams &params) = 0;
    virtual ~Observer() = default;
};