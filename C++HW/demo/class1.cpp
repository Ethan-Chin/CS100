#include"class1.h"
#include<iostream>
using namespace std;
class1::class1() : price(0)
{

}
class1::~class1()
{

}
void class1::showPrompt()
{
    cout << "something";
}
void class1::insertMoney(int money)
{
    balance += money;
}
void class1::showBalance()
{
    cout << balance;
}