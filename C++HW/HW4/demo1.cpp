#include <iostream>
#include <cstring>
using namespace std;
class DynamicArray
{
    private:
        int* data;
        int size;
        int capacity;
    public:
        DynamicArray();
        DynamicArray(const DynamicArray & other);
        ~DynamicArray();
        void assign(const DynamicArray & other);
        int getSize() const;
        int getCapacity() const;
        int at(int index) const;
        void push(const int item);
        bool remove(const int index);
        void print();
};
DynamicArray::DynamicArray() : data(NULL), size(0), capacity(5)
{
    data = new int[capacity];
}
DynamicArray::DynamicArray(const DynamicArray & other)
{
    data = new int[capacity];
    if(other.data == NULL)
    {
        delete [] data;
        data = NULL;
        size = 0;
        capacity = 0;
    }
    else
    {
        if (other.capacity <= 5)
        {
            delete [] data;
            capacity = other.capacity;
            data = new int[capacity];
            memcpy(data, other.data, sizeof(int) * other.size);
            size = other.size;
        }
        else
        {
            delete [] data;
            data = new int[other.capacity];
            for (int i = 5; i < (other.capacity); i = i * 2)
            {
                cout<<"(resize) from "<<i<<" to "<<i * 2<<endl;
            }
            capacity = other.capacity;
            memcpy(data, other.data, sizeof(int) * other.size);
            size = other.size;
        }
    }
}
DynamicArray::~DynamicArray()
{
    delete [] data;
    data = NULL;
    size = 0;
    capacity = 0;
}
void DynamicArray::assign(const DynamicArray & other)
{
    if (other.capacity <= capacity)
    {
        delete [] data;
        capacity = other.capacity;
        data = new int[capacity];
        memcpy(data, other.data, sizeof(int) * other.size);
        size = other.size;
    }
    else
    {
        delete [] data;
        data = new int[other.capacity];
        for (int i = capacity; i < (other.capacity); i = i * 2)
        {
            cout<<"(resize) from "<<i<<" to "<<i * 2<<endl;
        }
        capacity = other.capacity;
        memcpy(data, other.data, sizeof(int) * other.size);
        size = other.size;
    }
}
int DynamicArray::getSize() const
{
    return size;
}
int DynamicArray::getCapacity() const
{
    return capacity;
}
int DynamicArray::at(int index) const
{
    return *(data + index);
}
void DynamicArray::push(const int item)
{
    if (size + 1 >= capacity)
    {
        capacity = capacity * 2;
        cout<<"(resize) from "<<capacity/2<<" to "<<capacity<<endl;
        int* data_temp = new int[capacity];
        memcpy(data_temp, data, sizeof(int) * size);
        delete [] data;
        data_temp[size] = item;
        data = data_temp;
    }
    else
    {
        data[size] = item;
    }
    size++;
}
bool DynamicArray::remove(const int index)
{
    if (0 <= index <= size - 1)
    {
        int* data_temp = new int[capacity];
        memcpy(data_temp, data, sizeof(int) * index);
        memcpy((data_temp + index),  (data + index + 1), sizeof(int) * (size - index - 1));
        delete [] data;
        data = data_temp;
        size--;
        return true;
    }
    else
    {
        return false;
    }
}
/*void DynamicArray::print()
{
    for(int i = 0; i < size; i++)
    {
        cout<<data[i]<<endl;
    }
}
int main()
{
    DynamicArray A;
    for (int i = 0; i < 10; i++)
    {
        A.push(i);
    }
    
    A.remove(0);
    cout<<"at is"<<A.at(1)<<endl;
    A.print();
    DynamicArray B;
    B.assign(A);
    B.print();
    return 0;
}*/