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

#include "GameLogic.h"

void printPlayerHand(const std::vector<int>& hand,const std::string& playerName)
{
    std::cout << playerName << "'s hand: ";

    for (size_t i = 0;i < hand.size();i++)
    {
        std::cout << convertCardToString(hand[i]) << " ";
    }
    std::cout << std::endl;
}

void printRewardCards(const std::vector<int>& rewardCards)
{
    if (rewardCards.empty()) return;

    if (rewardCards.size() == SINGLE_CARD)
    {
        std::cout << "Current reward card: " << convertCardToString(rewardCards[0]) <<"\n\n";
    }
    else
    {
        std::cout << "Current reward cards: ";

        for (size_t i = 0; i < rewardCards.size(); i++)
        {
            std::cout << convertCardToString(rewardCards[i]) << " ";
        }
        std::cout <<"\n\n";
    }
}

void printWonCards(const std::vector<int>& wonCards, const std::string& playerName)
{
    std::cout << playerName << "'s won cards: ";

    if (wonCards.empty())
    {
        std::cout << "none";
    }
    else
    {
        for (size_t i = 0; i < wonCards.size(); i++)
        {
            std::cout << convertCardToString(wonCards[i]) << " ";
        }
    }
    std::cout << std::endl;
}

int chooseCard(std::vector<int>& hand, const std::string& playerName)
{
    std::string choiceString;
    int choice;

    while (true)
    {
        std::cout << playerName<< ",choose a card from your hand: ";
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

void printRoundResult(const std::string& player1Name,const std::string& player2Name,const int card1, 
    const int card2,int rewardCount, int winner)
{
    std::cout << player1Name << " played: " << convertCardToString(card1) << "\n";
    std::cout << player2Name << " played: " << convertCardToString(card2) << "\n";

    if (winner == PLAYER_ONE)
    {
        std::cout << player1Name << " wins the reward " << (rewardCount == SINGLE_CARD ? "card" : "cards") << "!\n";
    }
    else if (winner == PLAYER_TWO)
    {
        std::cout << player2Name << " wins the reward " << (rewardCount == SINGLE_CARD ? "card" : "cards") << "!\n";
    }
    else
    {
        std::cout << "Tie! Reward "<< (rewardCount == SINGLE_CARD ? "card": "cards") << " remain.\n";
    }
    std::cout << std::endl;
}

void moveRewardCards(std::vector<int>& src, std::vector<int>& dest) 
{
    for (size_t i = 0; i < src.size(); i++) 
    {
        dest.push_back(src[i]);
    }
    src.clear();
}

void takeRewardCard(std::vector<int>& rewardDeck, std::vector<int>& currentRewardCards)
{
    if (rewardDeck.empty()) return;

    currentRewardCards.push_back(rewardDeck.back());
    rewardDeck.pop_back();
}

int resolveRound(const int card1, const int card2, std::vector<int>& currentRewardCards,std::vector<int>& player1Won,
    std::vector<int>& player2Won,std::vector<int>& rewardDeck, bool& roundFinished,int& rewardCount)
{
    rewardCount = currentRewardCards.size();

    if (card1 > card2)
    {
        moveRewardCards(currentRewardCards, player1Won);
        roundFinished = true;
        return PLAYER_ONE;
    }
    else if (card2 > card1)
    {
        moveRewardCards(currentRewardCards, player2Won);
        roundFinished = true;
        return PLAYER_TWO;
    }
    else
    {
        takeRewardCard(rewardDeck, currentRewardCards);
        
        if (rewardDeck.empty())
        {
            roundFinished = true;
        }
        return TIE;
    }
}

void playSingleChoice(std::vector<int>& player1Hand,std::vector<int>& player2Hand,
    const std::string& player1Name,const std::string& player2Name,
    std::vector<int>& currentRewardCards,std::vector<int>& player1Won,
    std::vector<int>& player2Won,std::vector<int>& rewardDeck,bool& roundFinished)
{
    printRewardCards(currentRewardCards);

    printPlayerHand(player1Hand, player1Name);
    printWonCards(player1Won, player1Name);
    int card1 = chooseCard(player1Hand, player1Name);

    printPlayerHand(player2Hand, player2Name);
    printWonCards(player2Won, player2Name);
    int card2 = chooseCard(player2Hand, player2Name);

    int rewardCount = 0;
    int winner = resolveRound(card1, card2, currentRewardCards, player1Won, player2Won, rewardDeck, roundFinished,rewardCount);
    printRoundResult(player1Name,player2Name,card1, card2, rewardCount, winner);
}

void playRound(std::vector<int>& player1Hand,std::vector<int>& player2Hand,
    const std::string& player1Name, const std::string& player2Name,
    std::vector<int>& rewardDeck,std::vector<int>& player1Won,std::vector<int>& player2Won)
{
    if (rewardDeck.empty() || player1Hand.empty() || player2Hand.empty()) return;

    std::vector<int> currentRewardCards;
    takeRewardCard(rewardDeck, currentRewardCards);

    bool roundFinished = false;

    while (!roundFinished)
    {
        playSingleChoice(player1Hand, player2Hand, player1Name, player2Name, currentRewardCards,
            player1Won,player2Won, rewardDeck, roundFinished);
    }
}

int calculateSum(const std::vector<int>& cards)
{
    int sum = 0;
    for (size_t i = 0;i < cards.size(); i++)
    {
        sum += cards[i];
    }
    return sum;
}

void score(const std::string& player1Name,const std::string& player2Name, 
    const std::vector<int>& player1Won, const std::vector<int>& player2Won)
{
    int sum1 = calculateSum(player1Won);
    int sum2 = calculateSum(player2Won);

    std::cout << "\nGame over!\n";
    std::cout << player1Name << "'s total points: " << sum1 << std::endl;
    std::cout << player2Name << "'s total points: " << sum2 << std::endl;

    if (sum1 > sum2)
    {
        std::cout << player1Name << " wins the game!" << std::endl;
    }
    else if (sum2 > sum1)
    {
        std::cout << player2Name << " wins the game!" << std::endl;
    }
    else
    {
        std::cout << "The game is a tie!" << std::endl;
    }
}