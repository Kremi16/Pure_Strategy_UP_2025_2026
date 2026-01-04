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

    std::string player1Name, player2Name;
    std::string password1, password2;

    std::cout << "Enter Player 1 username: ";
    std::cin >> player1Name;
    if (!isUserExists(player1Name))
    {
        std::cout << "Creating new user profile.\n";
        std::cout << "Enter password: ";
        std::cin >> password1;
        isUserCreated(player1Name, password1);
    }
    else
    {
        std::cout << "Enter password for " << player1Name << ": ";
        std::cin >> password1;
        if (!isLoginSuccessful(player1Name, password1))
        {
            std::cout << "Incorrect password! Exiting.\n";
            return 0;
        }
    }

    std::cout << std::endl;
    std::cout << "Enter Player 2 username: ";
    std::cin >> player2Name;
    if (!isUserExists(player2Name))
    {
        std::cout << "Creating new user profile.\n";
        std::cout << "Enter password: ";
        std::cin >> password2;
        isUserCreated(player2Name, password2);
    }
    else
    {
        std::cout << "Enter password for " << player2Name << ": ";
        std::cin >> password2;
        if (!isLoginSuccessful(player2Name, password2))
        {
            std::cout << "Incorrect password! Exiting.\n";
            return 0;
        }
    }

    std::cout << std::endl;

    std::vector<int> player1Hand, player2Hand, rewardDeck;
    std::vector<int> player1Won, player2Won;

    initializeGame(player1Hand, player2Hand, rewardDeck);

    playGame(player1Hand, player2Hand, rewardDeck, player1Won, player2Won);

    updateAllStatistics(player1Name, player2Name, player1Won, player2Won);

	return 0;
}
