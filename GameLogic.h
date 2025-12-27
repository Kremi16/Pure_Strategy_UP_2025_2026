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