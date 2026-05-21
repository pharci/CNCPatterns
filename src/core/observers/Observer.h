// Observer.h
#pragma once

template <typename T>
class Observer {
  public:
    virtual void update(const T &params) = 0;
    virtual ~Observer() = default;
};