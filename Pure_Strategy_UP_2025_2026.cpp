#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
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

	shuffleDeck(rewardDeck);

	return 0;
}
