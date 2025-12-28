#pragma once
#include <iostream>
#include <vector>
#include <string>

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
* Header file with game logic functions.
*
*/

void printPlayerHand(const std::vector<int>& hand, int playerNumber);

void printRewardCards(const std::vector<int>& rewardCards);

int chooseCard(std::vector<int>& hand, const int playerNumber);

int resolveRound(int card1, int card2, std::vector<int>& currentRewardCards,std::vector<int>& player1Won, 
    std::vector<int>& player2Won,std::vector<int>& rewardDeck, bool& roundFinished);

void printRoundResult(int card1, int card2, const std::vector<int>& currentRewardCards, int winner);

void setRewardCards(std::vector<int>& src, std::vector<int>& dest);

void playSingleChoice(std::vector<int>& player1Hand,std::vector<int>& player2Hand,std::vector<int>& currentRewardCards,
    std::vector<int>& player1Won,std::vector<int>& player2Won,std::vector<int>& rewardDeck,bool& roundFinished);