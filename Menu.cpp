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
* File with implementation of the main menu logic functions.
*
*/

#include "Menu.h"
#include "UserProfiles.h"

std::string showMenu()
{
    std::cout << "1. Register new user\n";
    std::cout << "2. Login\n";
    std::cout << "3. Exit\n\n";
    std::cout << "Choose an option (1,2 or 3): ";

    std::string choice;
    std::cin >> choice;

    return choice;
}

void registerUser()
{
    std::string username, password;

    std::cout << "Enter new username: ";
    std::cin >> username;

    if (isUserExists(username))
    {
        std::cout << "Username already exists! Try again.\n\n";
        return;
    }

    std::cout << "Enter password: ";
    std::cin >> password;

    if (!isUserCreated(username, password))
    {
        std::cout << "Error creating user. Try again.\n\n";
    }
    else
    {
        std::cout << "User created successfully! You can now log in.\n\n";
    }
}

std::string login()
{
    std::string username, password;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (isLoginSuccessful(username, password))
    {
        std::cout << "Login successful! Welcome, " << username << "!\n\n";
        return username;
    }

    std::cout << "Invalid username or password! Try again.\n\n";
    return "";
}

std::string showMainMenu()
{
    const std::string EXIT = "3";
    const std::string REGISTRATION = "1";
    const std::string LOGIN = "2";

    while (true)
    {
        std::string choice = showMenu();

        if (choice == EXIT) return "";

        if (choice == REGISTRATION)
        {
            registerUser();
        }
        else if (choice == LOGIN)
        {
            std::string user = login();
            if (!user.empty()) return user;
        }
        else
        {
            std::cout << "Invalid choice! Try again.\n\n";
        }
    }
}

void loginTwoPlayers(std::string& player1, std::string& player2)
{
    std::cout << "--- Welcome to the card game Pure Strategy ---" << "\n\n";

    std::cout << "First player login:\n";
    player1 = showMainMenu();
    if (player1.empty()) return;

    std::cout << "Second player login:\n";
    player2 = showMainMenu();
    if (player2.empty()) return;

    std::cout << std::endl;

    std::cout << "\nLet the game begin!\n\n";
}