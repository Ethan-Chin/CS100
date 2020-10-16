#include <iostream>
#include <cstring>
using namespace std;
class CArray
{
    int size;  //数组元素的个数
    int* ptr;  //指向动态分配的数组
public:
    CArray(int s = 0);  //s代表数组元素的个数
    CArray(CArray & a);
    ~CArray();
    void push_back(int v);  //用于在数组尾部添加一个元素 v
    CArray & operator = (const CArray & a);  //用于数组对象间的赋值
    int length() const { return size; }  //返回数组元素个数
    int & operator[](int i)
    {  //用以支持根据下标访问数组元素，如“a[i]=4;”和“n=a[i];”这样的语句
        return ptr[i];
    };
};
CArray::CArray(int s) : size(s)
{
    if (s == 0)
        ptr = NULL;
    else
        ptr = new int[s];
}
CArray::CArray(CArray & a)
{
    if (!a.ptr) {
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}
CArray::~CArray()
{
    if (ptr) delete[] ptr;
}
CArray & CArray::operator=(const CArray & a)
{  //赋值号的作用是使 = 左边对象中存放的数组的大小和内容都与右边的对象一样
    if (ptr == a.ptr)  //防止 a=a 这样的赋值导致出错
        return *this;
    if (a.ptr == NULL) {  //如果a里面的数组是空的
        if (ptr)
            delete[] ptr;
        ptr = NULL;
        size = 0;
        return *this;
    }
    if (size < a.size) {  //如果原有空间够大，就不用分配新的空间
        if (ptr)
            delete[] ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int)*a.size);
    size = a.size;
    return *this;
}
void CArray::push_back(int v)
{  //在数组尾部添加一个元素
    if (ptr) {
        int* tmpPtr = new int[size + 1];  //重新分配空间
        memcpy(tmpPtr, ptr, sizeof(int) * size);  //复制原数组内容
        delete[] ptr;
        ptr = tmpPtr;
    }
    else  //数组本来是空的
        ptr = new int[1];
    ptr[size++] = v;  //加入新的数组元素
}
int main()
{
    CArray a;  //开始的数组是空的
    for (int i = 0; i<5; ++i)
        a.push_back(i);
    CArray a2, a3;
    a2 = a;
    for (int i = 0; i<a.length(); ++i)
        cout << a2[i] << " ";
    a2 = a3;  //a2 是空的
    for (int i = 0; i<a2.length(); ++i)  //a2.length()返回 0
        cout << a2[i] << " ";
    cout << endl;
    a[3] = 100;
    CArray a4(a);
    for (int i = 0; i<a4.length(); ++i)
        cout << a4[i] << " ";
    return 0;
}