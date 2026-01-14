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
* Header file with implementation of the main menu logic functions.
*
*/

#pragma once
#include <string>
#include "UserProfiles.h"

const std::string REGISTRATION = "1";
const std::string LOGIN = "2";
const std::string EXIT = "3";

std::string showMenu();

void registerUser();

std::string login();

std::string showMainMenu();

void loginTwoPlayers(std::string& player1, std::string& player2);