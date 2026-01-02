#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

bool isUserExists(const std::string& username);

bool isUserCreated(const std::string& username, const std::string& password);

bool isLoginSuccessful(const std::string& username, const std::string& password);