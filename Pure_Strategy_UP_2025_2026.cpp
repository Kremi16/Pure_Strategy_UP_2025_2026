#include <ctime>
#include "Cards.h"
#include "GameLogic.h"
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
* Main program file for the console implementation of the card game "Pure strategy".
*
*/

int main()
{
	std::srand(std::time(0));

	std::cout << "--- Welcome to the card game Pure Strategy ---" << "\n\n";

	std::vector<int> player1Hand, player2Hand, rewardDeck;	
	std::vector<int> player1Won, player2Won;

	initializeGame(player1Hand, player2Hand, rewardDeck);

	playGame(player1Hand, player2Hand, rewardDeck, player1Won, player2Won);

	return 0;
}
