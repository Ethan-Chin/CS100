#ifndef FUNCTIONAL_FORMS_HPP_
#define FUNCTIONAL_FORMS_HPP_

#include <stdlib.h>
#include <math.h>

/* For all lambda functions below, if you are not clear how they work, please refer to the given example for details. */


/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1+f2)(m) as first, and (d(f1+f2)/dx)(m) as second.
 */
auto derSum = [](auto f1, auto f2)
{
    return [=](auto m)
    {
        std::pair<double, double> result(f1(m).first + f2(m).first, f1(m).second + f2(m).second);
        return result;
    };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1-f2)(m) as first, and (d(f1-f2)/dx)(m) as second.
 */
auto derSub = [](auto f1, auto f2)
{
    return [=](double m)
    {
        std::pair<double, double> result(f1(m).first - f2(m).first, f1(m).second - f2(m).second);
        return result;
    };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1*f2)(m) as first, and (d(f1*f2)/dx)(m) as second.
 */
auto derMul = [](auto f1, auto f2)
{
    return [=](double m)
    {
        std::pair<double, double> result(f1(m).first * f2(m).first, f1(m).second * f2(m).first + f1(m).first * f2(m).second);
        return result;
    };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1/f2)(m) as first, and (d(f1/f2)/dx)(m) as second.
 */
auto derDiv = [](auto f1, auto f2)
{
    return [=](double m)
    {
        std::pair<double, double> result, r1 = f1(m), r2 = f2(m);
        result.first = r1.first / r2.first;
        result.second = (r1.second * r2.first - r2.second * r1.first) / std::pow(r2.first, 2);
        return result;
    };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1(f2))(m) as first, and (d(f1(f2))/dx)(m) as second.
 */
auto derComp = [](auto f1, auto f2)
{
    return [=](double m)
    {
        std::pair<double, double> result, r1 = f1(f2(m).first), r2 = f2(m);
        result.first = r1.first;
        result.second = r2.second * r1.second;
        return result;
    };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has [(f1)(m)]^exp as first, and (d(f1^exp)/dx)(m) as second.
 */
auto derPow = [](auto f, int exp)
{
    return [=](double m)
    {
        std::pair<double, double> result, r = f(m);
        result.first = std::pow(r.first, exp);
        result.second = exp * std::pow(r.first, exp - 1) * r.second;
        return result;
    };
};

#endif