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
* Header file with game session functions.
*
*/

#pragma once
#include "Cards.h"
#include "GameLogic.h"
#include "UserProfiles.h"

void initializeGame(std::vector<int>& player1Hand,std::vector<int>& player2Hand, std::vector<int>& rewardDeck);

void playGame(std::vector<int>& player1Hand, std::vector<int>& player2Hand,
	const std::string& player1Name, const std::string& player2Name,
	std::vector<int>& rewardDeck, std::vector<int>& player1Won, std::vector<int>& player2Won);

void updateAllStatistics(const std::string& player1Name, const std::string& player2Name,
	const std::vector<int>& player1Won, const std::vector<int>& player2Won);