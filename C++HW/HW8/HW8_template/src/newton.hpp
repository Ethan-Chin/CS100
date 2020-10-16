#ifndef NEWTON_HPP_
#define NEWTON_HPP_

#include <stdlib.h>
#include <cmath>

/*
 * This function finds the nearest root of a function by Newton's method.
 * f is a lambda function that's returned by any function in problem 2.
 * Starting from "startingPoint", you are to find a nearest root x_0, where
 * |x_0| < eps (0.000001 by default).
 */
template<typename T>
double findNearestRoot(T f, double startingPoint, double eps = 0.000001)
{
    double x = startingPoint;
    while (std::fabs(f(x).first) >= eps)
    {
        x = x - f(x).first / f(x).second;
    }
    return x;
}

#endif