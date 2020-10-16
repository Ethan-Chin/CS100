#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

class Person
{
public:


    Person(){};


    Person(const int& height, const float& weight)
    {
        _height = height;
        _weight = weight;
    };

    void showinfo()
    {
        std::cout<<_height<<','<<_weight<<std::endl;
    };


private:


int _height;
float _weight;

};




#endif