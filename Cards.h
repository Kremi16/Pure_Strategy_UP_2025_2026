#pragma once
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
* Header file with card-related functions.
*
*/

#include <cstdlib>

std::string numberToString(int number);

std::string convertCardToString(int card);

bool isNumberString(const std::string& s);

int stringToNumber(const std::string& s);

int parseCardInput(const std::string& card);

std::vector<int> createHand();

void mySwap(int& a, int& b);

void shuffleDeck(std::vector<int>& deck);