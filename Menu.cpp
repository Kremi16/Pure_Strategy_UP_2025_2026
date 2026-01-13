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

int showMenu()
{
    std::cout << "1. Register new user\n";
    std::cout << "2. Login\n";
    std::cout << "3. Exit\n\n";
    std::cout << "Choose an option: ";

    int choice;
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
    const int EXIT = 3;
    const int REGISTRATION = 1;
    const int LOGIN = 2;

    while (true)
    {
        int choice = showMenu();

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
