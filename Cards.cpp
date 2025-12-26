#include "Cards.h"

/**
*
* Solution to course project # 01
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Kremena Koleva
* @idnumber 9MI0600605
* @compiler VC
*
* File with implementation of card-related functions.
*
*/

const int MAX_CARDS_PER_HAND = 13;

std::string convertCardsToString(int card)
{
    if (card == 1) return "A";
    if (card == 11) return "J";
    if (card == 12) return "Q";
    if (card == 13) return "K";

    return std::to_string(card);
}

bool isNumberString(const std::string& s)
{
    if (s.empty()) return false;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9') return false;
    }

    return true;
}

int stringToNumber(const std::string& s)
{
    int num = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        num = num * 10 + (s[i] - '0');
    }

    return num;
}

int parseCardInput(const std::string& card)
{
    if (card == "A") return 1;
    if (card == "J") return 11;
    if (card == "Q") return 12;
    if (card == "K") return 13;

    if (isNumberString(card))
    {
        int num = stringToNumber(card);
        if (num >= 2 && num <= 10) return num;
    }

    return -1;
}

std::vector<int> createHand()
{
    std::vector<int> hand;

    for (int i = 1;i <= MAX_CARDS_PER_HAND;i++)
    {
        hand.push_back(i);
    }

    return hand;
}

void mySwap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void shuffleDeck(std::vector<int>& deck)
{
    for (size_t i = 0;i < deck.size();i++)
    {
        int randomIndex = rand() % deck.size();
        mySwap(deck[i], deck[randomIndex]);
    }
}
