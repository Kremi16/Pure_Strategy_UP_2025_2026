#include "GameLogic.h"
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
* File with implementation of game logic functions.
*
*/

void printPlayerHand(const std::vector<int>& hand, int playerNumber)
{
    std::cout << "Player " << playerNumber << " hand: ";

    for (size_t i = 0;i < hand.size();i++)
    {
        std::cout << convertCardsToString(hand[i]) << " ";
    }
    std::cout << std::endl;
}

void printRewardCards(const std::vector<int>& rewardCards)
{
    if (rewardCards.empty()) return;

    if (rewardCards.size() == 1)
    {
        std::cout << "Current reward card: " << convertCardsToString(rewardCards[0]) << std::endl;
    }
    else
    {
        std::cout << "Current reward cards: ";

        for (size_t i = 0; i < rewardCards.size(); i++)
        {
            std::cout << convertCardsToString(rewardCards[i]) << " ";
        }
        std::cout << std::endl;
    }
}

int chooseCard(std::vector<int>& hand, const int playerNumber)
{
    std::string choiceString;
    int choice;

    while (true)
    {
        std::cout << "Player " << playerNumber << " choose a card from your hand: ";
        std::cin >> choiceString;
        std::cout << std::endl;

        choice = parseCardInput(choiceString);
        if (choice == -1)
        {
            std::cout << "Invalid input, try again!" << std::endl;
            continue;
        }

        for (size_t i = 0; i < hand.size(); i++)
        {
            if (hand[i] == choice)
            {
                hand.erase(hand.begin() + i);
                return choice;
            }
        }
        std::cout << "You don't have that card in your hand, try again!" << std::endl;
    }
}