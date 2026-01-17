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
* File with implementation of the main game flow logic.
*
*/

#include "GameRunner.h"

int runTheGame()
{
    std::string player1, player2;

    if (!loginTwoPlayers(player1, player2))
    {
        std::cout << "\nGoodbye!" << std::endl;
        return 0;
    }

    std::vector<int> player1Hand, player2Hand, rewardDeck;
    std::vector<int> player1Won, player2Won;

    initializeGame(player1Hand, player2Hand, rewardDeck);

    playGame(player1Hand, player2Hand, player1, player2, rewardDeck, player1Won, player2Won);

    updateAllStatistics(player1, player2, player1Won, player2Won);

    displayEndGameStatistics(player1, player2);

    return 0;
}