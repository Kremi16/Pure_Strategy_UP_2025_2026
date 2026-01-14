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

#include "UserProfiles.h"

bool isUserExists(const std::string& username)
{
	std::ifstream file(username + ".txt");
	return file.good();
}

bool isUserCreated(const std::string& username, const std::string& password)
{
	if (isUserExists(username)) return false;

	std::ofstream file(username + ".txt");
	if (!file.is_open()) return false;

	file << password << "\n0 0\n";
	return true;
}

bool isLoginSuccessful(const std::string& username, const std::string& password)
{
	std::ifstream file(username + ".txt");
	if (!file.is_open()) return false;

	std::string enteredPassword;
	std::getline(file, enteredPassword);

	return (enteredPassword == password);
}

void loadProfile(const std::string& username, std::string& password, int& totalGames,
	int& totalWins, std::vector<std::string>& lines)
{
	std::ifstream file(username + ".txt");
	if (!file.is_open()) return;

	std::getline(file, password);
	file >> totalGames >> totalWins;
	file.ignore();

	lines.clear();
	std::string line;

	while (std::getline(file, line))
	{
		lines.push_back(line);
	}
}

void saveProfile(const std::string& username, const std::string& password, int totalGames,
	int totalWins, const std::vector<std::string>& lines)
{
	std::ofstream out(username + ".txt");

	out << password << "\n";
	out << totalGames << " " << totalWins << "\n";

	for (size_t i = 0; i < lines.size(); i++)
	{
		out << lines[i] << "\n";
	}
}

void updateStatistics(const std::string& username, bool won)
{
	std::string password;
	int totalGames = 0, totalWins = 0;
	std::vector<std::string> lines;
	
	loadProfile(username, password, totalGames, totalWins, lines);

	totalGames++;
	if (won) totalWins++;

	saveProfile(username, password, totalGames, totalWins, lines);
}

void parseOpponentLine(const std::string& line, std::string& opponent, int& games, int& wins)
{
	opponent.clear();
	games = 0;
	wins = 0;
    int field = FIELD_OPPONENT;
	int number = 0;

	for (size_t i = 0; i < line.length(); i++) 
	{
		if (line[i] == ' ') {
			if (field == FIELD_OPPONENT) {
				field = FIELD_GAMES;
			}
			else if (field == FIELD_GAMES) {
				games = number;
				number = 0;
				field = FIELD_WINS;
			}
		}
		else {
			if (field == FIELD_OPPONENT) {
				opponent += line[i];
			}
			else {
				number = number * 10 + (line[i] - '0');
			}
		}
	}

	if (field == FIELD_WINS) wins = number;
}

void updateOpponentStatistics(const std::string& username, const std::string& opponent, bool won)
{
	std::string password;
	int totalGames = 0, totalWins = 0;
	std::vector<std::string> lines;
	std::string line;

	loadProfile(username, password, totalGames, totalWins, lines);

	bool opponentFound = false;

	for (size_t i = 0; i < lines.size(); i++)
	{
		std::string opponentName;
		int gamesPlayed, gamesWon;

		parseOpponentLine(lines[i], opponentName, gamesPlayed, gamesWon);

		if (opponentName == opponent)
		{
			gamesPlayed++;
			if (won) gamesWon++;
			lines[i] = opponentName + " " + numberToString(gamesPlayed) + " " + numberToString(gamesWon);
			opponentFound = true;
			break;
		}
	}

	if (!opponentFound)
	{
		lines.push_back(opponent + " 1 " + (won ? "1" : "0"));
	}

	saveProfile(username, password, totalGames, totalWins, lines);
}

void showUserStatistics(const std::string& username)
{
	std::string password;
	int totalGames = 0, totalWins = 0;
	std::vector<std::string> opponents;

	loadProfile(username, password, totalGames, totalWins, opponents);

	std::cout << "Total games played: " << totalGames << "\n";
	std::cout << "Total games won: " << totalWins << " ("
		<< (totalGames ? (totalWins * 100.0 / totalGames) : 0) << "%)\n";

	std::cout << "Games against other players:\n";

	std::string opponent;
	int gamesPlayed, gamesWon;

	for (size_t i = 0; i < opponents.size(); i++)
	{
		parseOpponentLine(opponents[i], opponent, gamesPlayed, gamesWon);

		std::cout << opponent << ": " << gamesPlayed << " games played ("
			<< gamesWon << "/" << (gamesPlayed ? (gamesWon * 100.0 / gamesPlayed) : 0) << "% wins)\n";
	}
}

	void displayEndGameStatistics(const std::string & player1, const std::string & player2)
	{
		std::cout << "\n--- Player Statistics ---\n";
		std::cout << player1 << ":\n";
		showUserStatistics(player1);

		std::cout << "\n" << player2 << ":\n";
		showUserStatistics(player2);

		std::cout << "\nThank you for playing Pure Strategy!\n";
	}