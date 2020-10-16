#include <iostream>
#include "./build/config.h"

#ifdef USE_MYMATH
    #include "math/funny.h"
#else
    #include
#endif
#include "./math/funny.h"
using namespace std;
int main()
{
    int a = 1, b = 2;
    cout<<"I AM BACK NOW!!!"<<endl;
    int c;
    c = funny(a, b);
    cout<<c<<endl;
    return 0;
}