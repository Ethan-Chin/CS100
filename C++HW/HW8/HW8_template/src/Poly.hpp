#ifndef POLY_HPP_
#define POLY_HPP_

#include <stdlib.h>
#include <vector>
#include <cmath>

template<typename T>
class Poly
{
public:

    /* Default constructor */
    Poly(){};

    /* Constructor for a poly that's a constant number */
    Poly(T constant)
    {
        _coeffs.push_back(constant);
    };

    /* Given a vector of coefficients */
    Poly(const std::vector<T>& coeffs)
    {
        _coeffs = coeffs;
    };

    /* Given an rvalue reference of a vector of coefficients */
    Poly(std::vector<T>&& coeffs)
    {
        _coeffs = coeffs;
    };

    /* Given an array of coefficients with size of the array*/
    Poly(T * coeffs, size_t numberCoeffs)
    {
        for (int i = 0; i < numberCoeffs; i++)
        {
            _coeffs.push_back(*(coeffs + i));
        }
    };

    /* Given an initializer_list */
    Poly(std::initializer_list<T> coeffs)
    {
        for (auto i : coeffs)
        {
            _coeffs.push_back(i);
        }
    };

    virtual ~Poly(){};

    /* Copying constructor */
    Poly(const Poly<T>& poly)
    {
        _coeffs = poly._coeffs;
    };

    /* Copying constructor with rvalue reference */
    Poly(Poly<T>&& poly)
    {
        _coeffs = poly._coeffs;
    };

    /* Assignment operator */
    Poly<T>& operator=(const Poly<T>& poly)
    {
        _coeffs = poly._coeffs;
        return *this;
    };
  
    /* Assignment operator with rvalue reference */
    Poly<T>& operator=(Poly<T>&& poly)
    {
        _coeffs = poly._coeffs;
        return *this;
    };

    /*
    * Below are operations of polynomials.
    * They are quite self-explanatory.
    */

    Poly<T> operator+(const Poly<T>& rhs) const
    {
        Poly<T> temp(*this);
        if (temp._coeffs.size() < rhs._coeffs.size())
        {
            temp._coeffs.resize(rhs._coeffs.size());
        }
        for (int i = 0; i < rhs._coeffs.size(); i++)
        {
            temp._coeffs[i] += rhs._coeffs[i];
        }
        return temp;
    };

    Poly<T> operator-(const Poly<T>& rhs) const
    {
        Poly<T> temp(*this);
        if (temp._coeffs.size() < rhs._coeffs.size())
        {
            temp._coeffs.resize(rhs._coeffs.size());
        }
        for (int i = 0; i < rhs._coeffs.size(); i++)
        {
            temp._coeffs[i] -= rhs._coeffs[i];
        }
        return temp;
    };

    Poly<T> operator*(const Poly<T>& rhs) const
    {
        Poly<T> temp;
        temp._coeffs.resize(this->_coeffs.size() + rhs._coeffs.size() - 1);
        for (int i = 0; i < this->_coeffs.size(); i++)
        {
            for (int j = 0; j < rhs._coeffs.size(); j++)
            {
                temp._coeffs[i + j] += (this->_coeffs[i] * rhs._coeffs[j]);
            }
        }
        return temp;
    };

    Poly<T> & operator+=(const Poly<T>& rhs)
    {
        if (_coeffs.size() < rhs._coeffs.size())
        {
            _coeffs.resize(rhs._coeffs.size());
        }
        for (int i = 0; i < rhs._coeffs.size(); i++)
        {
            _coeffs[i] += rhs._coeffs[i];
        }
        return *this;
    };

    Poly<T> & operator-=(const Poly<T>& rhs)
    {
        if (_coeffs.size() < rhs._coeffs.size())
        {
            _coeffs.resize(rhs._coeffs.size());
        }
        for (int i = 0; i < rhs._coeffs.size(); i++)
        {
            _coeffs[i] -= rhs._coeffs[i];
        }
        return *this;
    };

    Poly<T> & operator*=(const Poly<T>& rhs)
    {
        Poly<T> temp(*this);
        _coeffs.resize(temp._coeffs.size() + rhs._coeffs.size() - 1);
        _coeffs.assign(_coeffs.size(), 0);
        for (int i = 0; i < temp._coeffs.size(); i++)
        {
            for (int j = 0; j < rhs._coeffs.size(); j++)
            {
                _coeffs[i + j] += (temp._coeffs[i] * rhs._coeffs[j]);
            }
        }
        return *this;
    };

    /* 
    * This function evaluates the polynomial at "param",
    * and returns the value of evaluation.
    * For example, evaluating x+3 at param=7 gives 10. 
    */
    T eval(T param) const
    {
        T result = 0;
        for (int i = 0; i < _coeffs.size(); i++)
        {
            result += (std::pow(param, i) * _coeffs[i]);
        }
        return result;
    };

    /* 
    * This function takes the derivative of the polynomial,
    * and returns a new polynomial of its derivative.
    * For example, calling this function for x^2
    * will return a polynomial 2x.
    */
    Poly<T> der() const
    {
        Poly<T> result;
        result._coeffs.resize(_coeffs.size() - 1);
        for (int i = 0; i < result._coeffs.size(); i++)
        {
            result._coeffs[i] = _coeffs[i + 1] * (i + 1);
        }
        return result;
    };

    /*
    * This function returns a pair of:
    * 1. the value (evaluation) of the polynomial at "param".
    * 2. the value of the first-order derivative of the polynomial at "param".
    * For example, calling this operator for x^2-2x at "param"=4
    * will return (8, 6).
    */
    std::pair<T, T> operator()(T param) const
    {
        std::pair<T, T> result;
        result.first = this->eval(param);
        result.second = (this->der()).eval(param);
        return result;
    };

private:
    std::vector<T> _coeffs;
};


#endif