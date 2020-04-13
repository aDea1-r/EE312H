#pragma once

#include "gtest/gtest.h"

#define ARRAYSIZE(a)        (sizeof(a) / sizeof(*a))

typedef double sqrtFun(double, double, double);
void testSquareRoot(double *vals, int len, sqrtFun fun);
