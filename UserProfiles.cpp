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

bool isValidUsernameOrPassword(const std::string& input)
{
	if (input.empty()) return false;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] < FIRST_PRINTABLE_ASCII || input[i] > LAST_PRINTABLE_ASCII) return false;

		if (input[i] == ' ') return false;
	}

	return true;
}

bool isUserCreated(const std::string& username, const std::string& password)
{
	if (!isValidUsernameOrPassword(username)) return false;
	if (!isValidUsernameOrPassword(password)) return false;

	if (isUserExists(username)) return false;

	std::ofstream file(username + ".txt");
	if (!file.is_open()) return false;

	file << password << "\n0 0\n";
	return true;
}

bool isLoginSuccessful(const std::string& username, const std::string& password)
{
	if (!isValidUsernameOrPassword(username)) return false;
	if (!isValidUsernameOrPassword(password)) return false;

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
	if (!file.good()) return;

	std::string filePassword;
	int fileTotalGames, fileTotalWins;

	if (!std::getline(file, filePassword)) return;
	if (!(file >> fileTotalGames >> fileTotalWins)) return;
	file.ignore();

	lines.clear();
	std::vector<std::string> fileLines;
	std::string line;

	while (std::getline(file, line))
	{
		fileLines.push_back(line);
	}

	password = filePassword;
	totalGames = fileTotalGames;
	totalWins = fileTotalWins;
	lines = fileLines;
}

void saveProfile(const std::string& username, const std::string& password, int totalGames,
	int totalWins, const std::vector<std::string>& lines)
{
	std::ofstream out(username + ".txt");
	if (!out.is_open()) return;

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

bool parseOpponentLine(const std::string& line, std::string& opponent, int& games, int& wins)
{
	opponent.clear();
	games = 0;
	wins = 0;
    int field = FIELD_OPPONENT;
	int number = 0;
	int fieldsCount = 1;

	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] == ' ') {
            if ((i == 0) || (line[i-1]==' ')) return false;

			if (field == FIELD_OPPONENT) {
				field = FIELD_GAMES;
				fieldsCount++;
			}
			else if (field == FIELD_GAMES) {
				games = number;
				number = 0;
				field = FIELD_WINS;
				fieldsCount++;
			}
		}
		else {
			if (field == FIELD_OPPONENT) {
				opponent += line[i];
			}
			else {
				if (line[i] < '0' || line[i] > '9') return false;
				number = number * 10 + (line[i] - '0');
			}
		}
	}

	if (field == FIELD_WINS){
		wins = number;
	}

	return (fieldsCount == OPPONENT_FIELDS_COUNT);
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

		if(!parseOpponentLine(lines[i], opponentName, gamesPlayed, gamesWon)) continue;

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

std::string formatPercentage(double value)
{
	int rounded = (int)(value * 100 + 0.5);
	int whole = rounded / 100;
	int fraction = rounded % 100;

	if (fraction == 0)
	{
		return numberToString(whole) + "%";
	}

	std::string result = numberToString(whole) + ".";

	if (fraction < 10) result += "0";

	result += numberToString(fraction);
	result += "%";

	return result;
}

void showUserStatistics(const std::string& username)
{
	std::string password;
	int totalGames = 0, totalWins = 0;
	std::vector<std::string> opponents;

	loadProfile(username, password, totalGames, totalWins, opponents);

	std::cout << "Total games played: " << totalGames << "\n";

	double totalWinRate = (totalGames ? (totalWins * 100.0 / totalGames) : 0);

	std::cout << "Total games won: " << totalWins << " (" << formatPercentage(totalWinRate) << ")\n";

	std::cout << "Games against other players:\n";

	std::string opponent;
	int gamesPlayed, gamesWon;

	for (size_t i = 0; i < opponents.size(); i++)
	{
		if(!parseOpponentLine(opponents[i], opponent, gamesPlayed, gamesWon)) continue;

		double winRate = (gamesPlayed ? (gamesWon * 100.0 / gamesPlayed) : 0);

		std::cout << opponent << ": " << gamesPlayed << " games played ("
			<< gamesWon << "/" << formatPercentage(winRate)<< " wins)\n";
		
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