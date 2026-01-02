#include "GameSession.h"

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
* File with implementation of game session functions.
*
*/

void initializeGame(std::vector<int>& player1Hand, std::vector<int>& player2Hand, std::vector<int>& rewardDeck)
{
	player1Hand = createHand();
	player2Hand = createHand();
	rewardDeck = createHand();
	shuffleDeck(rewardDeck);
}

void playGame(std::vector<int>& player1Hand, std::vector<int>& player2Hand,
	std::vector<int>& rewardDeck, std::vector<int>& player1Won, std::vector<int>& player2Won)
{
	while (!player1Hand.empty() && !player2Hand.empty() && !rewardDeck.empty())
	{
		playRound(player1Hand, player2Hand, rewardDeck, player1Won, player2Won);
	}

	score(player1Won, player2Won);
}
