#include "lotterystation.h"

LotteryStation::LotteryStation() : m_round(0)
{
}

LotteryStation::~LotteryStation()
{
}

LotteryTicket* LotteryStation::buy(CustomSet<int> numbers, const int tickettype)
{
    if ((tickettype == LOTTO7) && ((numbers.size() >= 7) && numbers.inBound(1, 30)))
    {
        Lotto7Ticket* buyticket = new Lotto7Ticket(numbers, m_round);
        cout<<"Bought a Lotto 7 ticket for "<<buyticket->getCost()<<" Yuan at round "<<m_round<<".\n";
        return buyticket;
    }
    else if ((tickettype == LOTTO6) && ((numbers.size() >= 6) && numbers.inBound(1, 43)))
    {
        Lotto6Ticket* buyticket = new Lotto6Ticket(numbers, m_round);
        cout<<"Bought a Lotto 6 ticket for "<<buyticket->getCost()<<" Yuan at round "<<m_round<<".\n";
        return buyticket;
    }
    cout<<"Failed.\n";
    return nullptr;
}

void LotteryStation::claimPrize(LotteryTicket* ticket)
{
    int bonus = 0;
    if (ticket)
    {
        if (ticket->getCost())
        {
            ticket->setCost(0);
            if (ticket->getTicketType() == LOTTO7)
            {
                bonus = ticket->claimPrize(prizeNumbers_7, m_round);
            }
            else if (ticket->getTicketType() == LOTTO6)
            {
                bonus = ticket->claimPrize(prizeNumbers_6, m_round);
            }
        }
    }
    cout<<"This ticket wins "<<bonus<<" Yuan.\n";
}
void LotteryStation::newRound()
{
    prizeNumbers_7.initialize();
    prizeNumbers_6.initialize();
    for (int i = 0; i < LOTTO7;)
    {
        if (prizeNumbers_7.add(randInt(1, 30)))
        {
            i++;
        }
    }
    for (int i = 0; i < LOTTO6;)
    {
        if (prizeNumbers_6.add(randInt(1, 43)))
        {
            i++;
        }
    }
    m_round++;
}

bool LotteryStation::setPrizeNumbers(CustomSet<int> numbers, const int tickettype)
{
    if (tickettype != numbers.size())
    {
        return false;
    }
    if (tickettype == LOTTO7 && numbers.inBound(1, 30))
    {
        prizeNumbers_7.initialize();
        prizeNumbers_7 = numbers;
        return true;
    }
    else if (tickettype == LOTTO6 && numbers.inBound(1, 43))
    {
        prizeNumbers_6.initialize();
        prizeNumbers_6 = numbers;
        return true;
    }
    return false;
}

int randInt(int min, int max)
{
    if (max < min)
    {
	    swap(max, min);
    }
    return rand() % (max - min + 1) + min;
}