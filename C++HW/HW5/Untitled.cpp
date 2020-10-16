#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int ERRORCODE = -1;

class DataAnalyser
{
public:
    DataAnalyser(){qwqwqw = 0;wewe = 0;}
    ~DataAnalyser(){};
    float calculate(float* data, size_t size);
    int addone(){int result = qwqwqw + 1;return result;}
    int print(){cout<<qwqwqw<<'.'<<wewe<<endl;return 0;}
private:
    int ahahaha();
    int qwqwqw;
    int wewe;
};

int main()
{
    DataAnalyser d;
    d.print();
    return 0;
}