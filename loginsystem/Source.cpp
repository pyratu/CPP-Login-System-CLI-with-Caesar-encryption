#include <iostream>
#include "AppFunctions.h"

int main()
{
	while (true)
	{
		int choice;
		bool validInput = false;

		do {
			std::cout << "\nSelect a choice\n1: register\n2: login\n3: forgot password\n4: exit\nYour Choice:";
			std::cin >> choice;

			// Check if the input is a number
			if (std::cin.fail()) {
				std::system("CLS");
				std::cout << "\nwrong choice";
				std::cin.clear(); // Clear the error flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
			}
			else 
				validInput = true;

		} while (!validInput);

		switch (choice)
		{
			case 1:
			{
				std::string username, password;
				std::cout << "Select a username: ";
				std::cin >> username;
				std::cout << "Select a password: ";
				std::cin >> password;
				AppFunctions::registerAccount(username, password);
				break;
			}

			case 2:
			{
				std::string username, password;
				std::cout << "Select a username: ";
				std::cin >> username;
				std::cout << "Select a password: ";
				std::cin >> password;
				AppFunctions::login(username, password);
				break;
			}
			case 3:
			{
				std::cout << "type your username: ";
				std::string username;
				std::cin>>username;
				AppFunctions::forgotpassword(username);
				break;
			}
			case 4:
			{
				return 0;
			}
			default:
			{
				std::system("CLS");
				std::cout << "Incorrect choice. Please provide a choice that is stated in the menu\n";
				std::cout << "\nSelect a choice\n1: register\n2: login\n3: forgot password\n4: exit\nYour Choice:\n";
				std::cin >> choice;
				break;
			}
		}
		std::system("CLS");
	}
}
