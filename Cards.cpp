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

#include "Cards.h"

std::string numberToString(int number)
{
    std::string result = "";

    while (number > 0)
    {
        char digit = char('0' + (number % 10));
        result = digit + result;
        number /= 10;
    }
    return result;
}

std::string convertCardToString(int card)
{
    if (card == 1) return "A";
    if (card == 11) return "J";
    if (card == 12) return "Q";
    if (card == 13) return "K";

    return numberToString(card);
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
        if (num >= MIN_NUM_CARD && num <= MAX_NUM_CARD) return num;
    }

    return INVALID_CARD;
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
