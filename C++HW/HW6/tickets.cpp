#include "tickets.h"

LotteryTicket::LotteryTicket()
{
    m_cost = 0;
    m_round = 1;
}

LotteryTicket::LotteryTicket(const CustomSet<int>& numbers, int round)
{
    m_cost = 0;
    m_numbers += numbers;
    m_round = round;
}


LotteryTicket::~LotteryTicket() 
{
}

const CustomSet<int> LotteryTicket::getNumbers() const
{
    return m_numbers;
}

const int LotteryTicket::getRound() const
{
    return m_round;
}
const int LotteryTicket::getCost() const
{
    return m_cost;
}

void LotteryTicket::setCost(const int& cost)
{
    m_cost = cost;
}

Lotto7Ticket::Lotto7Ticket()
{
}

Lotto7Ticket::Lotto7Ticket(const CustomSet<int>& numbers, int round) : LotteryTicket(numbers, round)
{
    int cost = 2 * caculatorInOrder(7, numbers.size());
    this->setCost(cost);
}

Lotto7Ticket::~Lotto7Ticket()
{
}

const int Lotto7Ticket::getTicketType() const
{
    return LOTTO7;
}

const int Lotto7Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round) const
{
    if (round == this->getRound())
    {
        int const ticketSize = this->getNumbers().size();
        int const inPizeSize = (this->getNumbers().intersection(prizeNumbers)).size();
        int prize[7] = {0, 0, 0, 0, 0, 0, 0};
        long long getMoney = 0;
        for (int i = inPizeSize; (i > 0) && ((7 - i) <= (ticketSize - inPizeSize)); i--)
        {
            prize[i - 1] = caculatorInOrder(i, inPizeSize) * caculatorInOrder((7 - i), (ticketSize - inPizeSize));
        }
        getMoney = prize[6] * 2000000 + prize[5] * 4500 + prize[4] * 75 + prize[3] * 5;
        return getMoney;
    }
    return 0;
}

Lotto6Ticket::Lotto6Ticket()
{
}

Lotto6Ticket::Lotto6Ticket(const CustomSet<int>& numbers, int round) : LotteryTicket(numbers, round)
{
    int cost = 2 * caculatorInOrder(6, numbers.size());
    this->setCost(cost);
}

Lotto6Ticket::~Lotto6Ticket()
{
}

const int Lotto6Ticket::getTicketType() const
{
    return LOTTO6;
}

const int Lotto6Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round) const
{
    if (round == this->getRound())
    {
        int const ticketSize = this->getNumbers().size();
        int const inPizeSize = (this->getNumbers().intersection(prizeNumbers)).size();
        int prize[6] = {0, 0, 0, 0, 0, 0};
        int getMoney = 0;
        for (int i = inPizeSize; (i > 0) && ((6 - i) <= (ticketSize - inPizeSize)); i--)
        {
            prize[i - 1] = caculatorInOrder(i, inPizeSize) * caculatorInOrder((6 - i), (ticketSize - inPizeSize));
        }
        getMoney = prize[5] * 2000000 + prize[4] * 4500 + prize[3] * 75 + prize[2] * 5;
        return getMoney;
    }
    return 0;
}

long long caculatorInOrder(const int usize, const int dsize)
{
    long long up = 1;
    long long down = 1;
    for (int i = 0; i < usize; i++)
    {
        up = up * (usize - i);
        down = down * (dsize - i);
    }
    long long result = (down / up);
    return result;
}