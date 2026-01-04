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

void updateAllStatistics(const std::string& player1Name, const std::string& player2Name,
    const std::vector<int>& player1Won, const std::vector<int>& player2Won)
{
    bool player1Victory = false;
    bool player2Victory = false;

    int sum1 = calculateSum(player1Won);
    int sum2 = calculateSum(player2Won);

    if (sum1 > sum2)
    {
        player1Victory = true;
    }
    else if (sum2 > sum1)
    {
        player2Victory = true;
    }

    updateStatistics(player1Name, player1Victory);
    updateStatistics(player2Name, player2Victory);

    updateOpponentStatistics(player1Name, player2Name, player1Victory);
    updateOpponentStatistics(player2Name, player1Name, player2Victory);
}