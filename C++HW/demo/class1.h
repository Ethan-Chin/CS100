#ifndef CLASS1_H
#define CLASS1_H
class  class1
{
public:
    class1(/* args */);
    virtual ~ class1();
    void showPrompt();
    void insertMoney(int money);
    void showBalance();
    void printTicket();
    void showTotal();
private:
    const int price;
    int balance;
    int total;
};
#endif