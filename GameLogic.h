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

#pragma once
#include <iostream>
#include <vector>
#include <string>

void printPlayerHand(const std::vector<int>& hand, const std::string& playerName);

void printRewardCards(const std::vector<int>& rewardCards);

int chooseCard(std::vector<int>& hand, const std::string& playerName);

void takeRewardCard(std::vector<int>& rewardDeck, std::vector<int>& currentRewardCards);

int resolveRound(const int card1, const int card2, std::vector<int>& currentRewardCards,std::vector<int>& player1Won, 
    std::vector<int>& player2Won,std::vector<int>& rewardDeck, bool& roundFinished, int& rewardCount);

void printRoundResult(const std::string& player1Name, const std::string& player2Name, 
    const int card1, const int card2, int rewardCount, int winner);

void moveRewardCards(std::vector<int>& src, std::vector<int>& dest);

void playSingleChoice(std::vector<int>& player1Hand, std::vector<int>& player2Hand,
    const std::string& player1Name, const std::string& player2Name,
    std::vector<int>& currentRewardCards, std::vector<int>& player1Won,
    std::vector<int>& player2Won, std::vector<int>& rewardDeck, bool& roundFinished);

void playRound(std::vector<int>& player1Hand, std::vector<int>& player2Hand,
    const std::string& player1Name, const std::string& player2Name,
    std::vector<int>& rewardDeck, std::vector<int>& player1Won, std::vector<int>& player2Won);

int calculateSum(const std::vector<int>& cards);

void score(const std::string& player1Name, const std::string& player2Name,
    const std::vector<int>& player1Won, const std::vector<int>& player2Won);