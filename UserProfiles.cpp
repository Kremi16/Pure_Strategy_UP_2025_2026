#include "UserProfiles.h"

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
* File with implementation of user profile management functions.
*
*/

bool isUserExists(const std::string& username)
{
	std::ifstream file("profiles/" + username + ".txt");
	return file.good();
}

bool isUserCreated(const std::string& username, const std::string& password)
{
	if (isUserExists(username)) return false;

	std::ofstream file("profiles/" + username + ".txt");
	if (!file.is_open()) return false;

	file << password << "\n0 0\n";
	return true;
}

bool isLoginSuccessful(const std::string& username, const std::string& password)
{
	std::ifstream file("profiles/" + username + ".txt");
	if (!file.is_open()) return false;

	std::string enteredPassword;
	std::getline(file, enteredPassword);

	return (enteredPassword == password);
}