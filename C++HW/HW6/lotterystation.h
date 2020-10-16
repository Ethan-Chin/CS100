#ifndef LOTTERYSTATION_H_
#define LOTTERYSTATION_H_
#include "tickets.h"

class LotteryStation
{
public:
	LotteryStation();
	~LotteryStation();

	LotteryTicket* buy(const CustomSet<int> numbers,const int tickettype);
	void claimPrize(LotteryTicket* ticket);
	void newRound();
	bool setPrizeNumbers(const CustomSet<int> numbers, const int tickettype);
private:
	int m_round;
	CustomSet<int> prizeNumbers_7;
	CustomSet<int> prizeNumbers_6;
};

int randInt(int min, int max);
#endif
