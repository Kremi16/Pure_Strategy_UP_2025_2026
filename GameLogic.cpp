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
    const int INVALID_CARD = -1;

    while (true)
    {
        std::cout << "Player " << playerNumber << " choose a card from your hand: ";
        std::cin >> choiceString;
        std::cout << std::endl;

        choice = parseCardInput(choiceString);
        if (choice == INVALID_CARD)
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

void printRoundResult(int card1, int card2, const std::vector<int>& currentRewardCards, int winner)
{
    const int PLAYER_ONE = 1;
    const int PLAYER_TWO = 2;

    int rewardCount = currentRewardCards.size();
    std::cout << "Player 1 played: " << convertCardsToString(card1) << "\n";
    std::cout << "Player 2 played: " << convertCardsToString(card2) << "\n";

    if (winner == PLAYER_ONE)
    {
        std::cout << "Player 1 wins the reward " << (rewardCount == 1 ? "card" : "cards") << "!\n";
    }
    else if (winner == PLAYER_TWO)
    {
        std::cout << "Player 2 wins the reward " << (rewardCount == 1 ? "card" : "cards") << "!\n";
    }
    else
    {
        std::cout << "Tie! Reward " << (rewardCount == 1 ? "card" : "cards") << " remain.\n";
    }
    std::cout << std::endl;
}

void setRewardCards(std::vector<int>& src, std::vector<int>& dest) 
{
    for (size_t i = 0; i < src.size(); i++) 
    {
        dest.push_back(src[i]);
    }
}

int resolveRound(int card1, int card2, std::vector<int>& currentRewardCards,std::vector<int>& player1Won,
    std::vector<int>& player2Won,std::vector<int>& rewardDeck, bool& roundFinished)
{
    const int PLAYER_ONE_WIN = 1;
    const int PLAYER_TWO_WIN = 2;
    const int TIE = 0;

    if (card1 > card2)
    {
        setRewardCards(currentRewardCards, player1Won);
        roundFinished = true;
        return PLAYER_ONE_WIN;
    }
    else if (card2 > card1)
    {
        setRewardCards(currentRewardCards, player2Won);
        roundFinished = true;
        return PLAYER_TWO_WIN;
    }
    else
    {
        if (!rewardDeck.empty())
        {
            currentRewardCards.push_back(rewardDeck.back());
            rewardDeck.pop_back();
        }
        else
        {
            roundFinished = true;
        }
        return TIE;
    }
}

void playSingleChoice(std::vector<int>& player1Hand,std::vector<int>& player2Hand,
    std::vector<int>& currentRewardCards,std::vector<int>& player1Won,
    std::vector<int>& player2Won,std::vector<int>& rewardDeck,bool& roundFinished)
{
    const int PLAYER_ONE = 1;
    const int PLAYER_TWO = 2;

    printRewardCards(currentRewardCards);

    printPlayerHand(player1Hand, PLAYER_ONE);
    int card1 = chooseCard(player1Hand, PLAYER_ONE);

    printPlayerHand(player2Hand, PLAYER_TWO);
    int card2 = chooseCard(player2Hand, PLAYER_TWO);

    int winner = resolveRound(card1, card2, currentRewardCards, player1Won, player2Won, rewardDeck, roundFinished);
    printRoundResult(card1, card2, currentRewardCards, winner);
}