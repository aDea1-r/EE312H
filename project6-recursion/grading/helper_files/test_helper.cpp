#include "test_helper.h"
#include "MazeParams.h"
#include "Recursion.h"
#include <cmath>

Maze maze;
Maze maze_soln;
int MAZE_SIZE = 20;

static double getDelta(double val);

static double absolute_value(double x)
{
    return (x < 0) ? (x * -1) : x;
}

void testSquareRoot(double *vals, int len, sqrtFun fun)
{
    for (int i = 0; i < len; i++)
    {
        double val = fun(vals[i], 0, vals[i]);
        double expect = sqrt(vals[i]);
        double delta = getDelta(expect);

        EXPECT_LE(absolute_value(val - expect), delta);
    }
}

double getDelta(double val)
{
    double delta = 1.0;

    if (val == 0)
    {
        // Only zero is within 15 decimal digits of zero, but be nice
        return 1e-15;
    }

    while (val >= 1)
    {
        delta *= 10;
        val /= 10;
    }
    while (val < 0.1)
    {
        delta /= 10;
        val *= 10;
    }

    return delta * 1e-14;
}

