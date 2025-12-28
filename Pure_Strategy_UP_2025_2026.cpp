#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Cards.h"
#include "GameLogic.h"

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
* Main program file for the console implementation of the card game "Pure strategy".
*
*/

int main()
{
	std::srand(std::time(0));

	std::cout << "Welcome to the card game Pure Strategy!" << "\n\n";

	std::vector<int> player1Hand = createHand();
	std::vector<int> player2Hand = createHand();
	std::vector<int> rewardDeck = createHand();	
	std::vector<int> player1Won, player2Won;
    std::vector<int> currentRewardCards;

    bool roundFinished = false;

    shuffleDeck(rewardDeck);

    currentRewardCards.push_back(rewardDeck.back());
    rewardDeck.pop_back();

    printPlayerHand(player1Hand, 1);
    printPlayerHand(player2Hand, 2);
    printRewardCards(currentRewardCards);

    int card1 = chooseCard(player1Hand, 1);
    int card2 = chooseCard(player2Hand, 2);

    int winner = resolveRound(card1, card2, currentRewardCards, player1Won, player2Won, rewardDeck, roundFinished);

    printRoundResult(card1, card2, currentRewardCards, winner);

	return 0;
}
