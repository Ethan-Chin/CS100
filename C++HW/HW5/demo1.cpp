#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int ERRORCODE = -1;

class DataAnalyser
{
public:
    DataAnalyser() {};
    virtual ~DataAnalyser() {};
    /** 
     * virtual function "calculate"
     * @param data: the data array need to be calculated
     * @param size: the length of the data
     * @return: the calculated result
     */
    
    virtual float calculate(float* data, size_t size)
    {
        std::cout << "ERROR: Try to access virtual function which is in base class" << std::endl;
        return ERRORCODE;
    };
};


// MaximumAnalyser
class MaximumAnalyser : public DataAnalyser
{
    // Your code here.
public:
    MaximumAnalyser() {};
    virtual ~MaximumAnalyser() {};
    virtual  float calculate(float* data, size_t size)
    {
        float max = *data;
        for(int i = 0; i < size; i++)
        {
            if(*(data + i) > max)
            {
                max = *(data + i);
            }
        }
        return max;
    };
};

// MinimumAnalyser
class MinimumAnalyser : public DataAnalyser
{
    // Your code here.
public:
    MinimumAnalyser() {};
    virtual ~MinimumAnalyser() {};
    virtual  float calculate(float* data, size_t size)
    {
        float min = *data;
        for(int i = 0; i < size; i++)
        {
            if(*(data + i) < min)
            {
                min = *(data + i);
            }
        }
        return min;
    };
};

// AverageAnalyser
class AverageAnalyser : public DataAnalyser
{
    // Your code here.
public:
    AverageAnalyser() {};
    virtual ~AverageAnalyser() {};
    virtual  float calculate(float* data, size_t size)
    {
        float sum = 0;
        for(int i = 0; i < size; i++)
        {
            sum += *(data + i);
        }
        float average = sum / size;
        return average;
    };
};

// MedianAnalyser
class MedianAnalyser : public DataAnalyser
{
    // Your code here.
public:
    virtual  float calculate(float* data, size_t size)
    {
        float tem;
        for(int i = 0; i < size; i++)
        {
            for (int j = 1; j < size; j++)
            {
                if (data[j - 1] > data[j])
                {
                    tem = data[j - 1];
                    data[j - 1] = data[j];
                    data[j] = tem;
                }
            }
        }
        if ((size % 2) == 0)
        {
            return ((data[(size / 2) - 1] + data[size / 2]) / 2);
        }
        else
        {
            return(data[((size + 1) / 2) - 1]);
        }
    };
};

// StdDevAnalyser
class StdDevAnalyser : public DataAnalyser
{
    // Your code here
public:
    virtual  float calculate(float* data, size_t size)
    {
        AverageAnalyser aser;
        float average = aser.calculate(data, size);
        float sum = 0, stdDev;
        for (int i = 0; i < size; i++)
        {
            sum += pow((data[i] - average), 2);
        }
        return sqrt(sum / size);
    }
};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    /* Your can write your own main for testing */
    float arr[] = {0.3, -100, 1, 2, 5, 6, 9, 12, 2};
    DataAnalyser* foo = new StdDevAnalyser();  /* it can be any of the required 5 child classes */        
    std::cout << foo->calculate(arr, 9) << std::endl; /* should be -100 in this case */     
    delete foo; 
    return 0;
}