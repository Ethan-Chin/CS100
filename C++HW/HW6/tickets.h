#ifndef TICKETS_H_
#define TICKETS_H_
#include "customset.h"
#define LOTTO6 6
#define LOTTO7 7

class LotteryTicket
{
public:
	LotteryTicket();
	LotteryTicket(const CustomSet<int>& numbers, int round);
	virtual ~LotteryTicket();
    const CustomSet<int> getNumbers() const;
	const int getRound() const;
	const int getCost() const;
	virtual const int getTicketType() const = 0;
	void setCost(const int& cost);
	virtual const int claimPrize(const CustomSet<int>& prizeNumbers, int round) const = 0;
private:
	CustomSet<int> m_numbers;
	int m_round;
	int m_cost;
};

class Lotto7Ticket : public LotteryTicket
{
public:
    Lotto7Ticket();
    Lotto7Ticket(const CustomSet<int>& numbers, int round);
    ~Lotto7Ticket();
    const int getTicketType() const;
    const int claimPrize(const CustomSet<int>& prizeNumbers, int round) const;
};

class Lotto6Ticket : public LotteryTicket
{
public:
    Lotto6Ticket();
    Lotto6Ticket(const CustomSet<int>& numbers, int round);
    ~Lotto6Ticket();
    const int getTicketType() const;
    const int claimPrize(const CustomSet<int>& prizeNumbers, int round) const;
};
long long caculatorInOrder(int usize, int dsize);
#endif