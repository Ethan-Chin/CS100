#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

class LookupTable
{
public:
    // constructor, start: start position; end: end position; increment: the increment "dx"
    // You should calculate the value in range [start, end], with increment "increment"
    LookupTable(double start, double end, double increment){};
    // virtual destructor
    virtual ~LookupTable() = 0;
    // get the value f(x) of the given x
    virtual double getValue(double x) = 0;
    double InputOutOfRangeError()
    {
        return 0;
    };
};

LookupTable::~LookupTable()
{
}

class SquareLookupTable : public LookupTable
{
public:
    SquareLookupTable(double start, double end, double increment):LookupTable(start, end, increment)
    {
        int times = (end - start) / increment + 1;
        itincrement = increment;
        for (int i = 0; i < times; i++)
        {
            double x0 = start + i * increment;
            double y0 = pow(x0, 2);
            table[x0] = y0;
        }
    };
    double getValue(double x)
    {
        if (table.count(x))
        {
            return table[x];
        }
        map <double,double>::iterator it;
        for (it = table.begin() ; it !=table.end(); it++)
        {   
            if ((it->first < x) && (x < it->first + itincrement) && (table.count(it->first + itincrement)))
            {
                return ((x - it -> first) * table[(it -> first) + itincrement] + ((it -> first) + itincrement - x) * table[it -> first]) / itincrement;
            }
        }
        return InputOutOfRangeError();
    };
    ~SquareLookupTable(){};
private:
    map <double, double> table;
    double itincrement;
};

class SinLookupTable : public LookupTable
{
public:
    SinLookupTable(double start, double end, double increment):LookupTable(start, end, increment)
    {
        int times = (end - start) / increment + 1;
        itincrement = increment;
        for (int i = 0; i < times; i++)
        {
            double x0 = start + i * increment;
            double y0 = sin(x0);
            table[x0] = y0;
        }
    };
    double getValue(double x)
    {
        if (table.count(x))
        {
            return table[x];
        }
        map <double,double>::iterator it;
        for (it = table.begin() ; it !=table.end(); it++)
        {   
            if ((it->first < x) && (x < it->first + itincrement) && (table.count(it->first + itincrement)))
            {
                return ((x - it -> first) * table[(it -> first) + itincrement] + ((it -> first) + itincrement - x) * table[it -> first]) / itincrement;
            }
        }
        return InputOutOfRangeError();
    };
    ~SinLookupTable(){};
private:
    map <double, double> table;
    double itincrement;
};

class LogLookupTable : public LookupTable
{
public:
    public:
    LogLookupTable(double start, double end, double increment):LookupTable(start, end, increment)
    {
        int times = (end - start) / increment + 1;
        itincrement = increment;
        for (int i = 0; i < times; i++)
        {
            double x0 = start + i * increment;
            double y0 = log(x0);
            table[x0] = y0;
        }
    };
    double getValue(double x)
    {
        if (table.count(x))
        {
            return table[x];
        }
        map <double,double>::iterator it;
        for (it = table.begin() ; it !=table.end(); it++)
        {   
            if ((it->first < x) && (x < it->first + itincrement) && (table.count(it->first + itincrement)))
            {
                return ((x - it -> first) * table[(it -> first) + itincrement] + ((it -> first) + itincrement - x) * table[it -> first]) / itincrement;
            }
        }
        return InputOutOfRangeError();
    };
    ~LogLookupTable(){};
private:
    map <double, double> table;
    double itincrement;
};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    LogLookupTable a(0, 5, 1);
    cout<<a.getValue(0)<<endl;
    return 0;
}  