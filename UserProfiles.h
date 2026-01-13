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
* Header file with user profile management functions.
*
*/

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Cards.h"

bool isUserExists(const std::string& username);

bool isUserCreated(const std::string& username, const std::string& password);

bool isLoginSuccessful(const std::string& username, const std::string& password);

void loadProfile(const std::string& username, std::string& password, int& totalGames,
	int& totalWins, std::vector<std::string>& lines);

void saveProfile(const std::string& username, const std::string& password, int totalGames,
	int totalWins, const std::vector<std::string>& lines);

void updateStatistics(const std::string& username, bool won);

void parseOpponentLine(const std::string& line, std::string& opponent, int& games, int& wins);

void updateOpponentStatistics(const std::string& username, const std::string& opponent, bool won);

void showUserStatistics(const std::string& username);

void displayEndGameStatistics(const std::string& player1, const std::string& player2);