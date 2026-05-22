// Service.h
#pragma once
#include "common/pch.h"

template <typename Params> class OperationService {
  public:
    QString generate(const Params &params);
};