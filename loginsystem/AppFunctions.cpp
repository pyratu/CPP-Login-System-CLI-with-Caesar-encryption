#include "AppFunctions.h"
#include "encdec.h"
#include <iostream>
#include <fstream>
#include <string>


namespace AppFunctions {
	int shift = 5;
	void login(std::string username, std::string password)
	{
		std::string fileid, filepass;
		int passwordCheck = 0;
		std::ifstream file("login.txt");
		while (file >> fileid >> filepass)
		{
			fileid = security::decryptCaesar(fileid, shift);
			filepass = security::decryptCaesar(filepass, shift);
			if (fileid == username && filepass != password)
			{
				passwordCheck = 3;
				break;
			}
			else if (fileid == username && filepass == password)
			{
				passwordCheck = 1;
				break;
			}
			else if (fileid != username)
			{
				passwordCheck = 2;
			}
		}

		switch (passwordCheck)
		{
		case 1:
		{
			std::cout << "login succ\n";
			std::system("PAUSE");
			break;
		}
		case 2:
		{
			std::cout << "account not found\n";
			std::system("PAUSE");
			break;
		}
		case 3:
		{
			std::cout << "wrong password\n";
			std::system("PAUSE");
			break;
		}
		default:
		{
			std::cout << passwordCheck;
			std::cout << "error";
			system("PAUSE");
			break;
		}

		}
		file.close();
	}
	void registerAccount(std::string username, std::string password)
	{
		int usernameCheck;
		bool accountFound = false;
		std::string fileusername, filepass;
		std::string temp;
		do
		{
			std::ifstream check("login.txt");
			if (accountFound == true)
			{
				std::cout << "choose another username: ";
				std::cin >> username;
			}

			accountFound = false;
			while (check >> fileusername >> temp)
			{
				fileusername = security::decryptCaesar(fileusername, shift);
				if (fileusername == username)
				{
					accountFound = true;
					break;
				}
			}

			if (accountFound == true)
			{
				std::cout << "account name already exists\n";
				std::system("PAUSE");
			}
			check.close();

		} while (accountFound == true);

		if (accountFound == false)
		{
			std::ofstream file("login.txt", std::ios::app);
			username = security::encryptCaesar(username, shift);
			password = security::encryptCaesar(password, shift);
			file << username << ' ' << password << std::endl;
			file.close();
			std::cout << "register succsesful\n";
			std::system("PAUSE");
		}
	}
	void forgotpassword(std::string username)
	{
		std::string fileid, filepass;
		bool userNotFound = true;
		std::ifstream file("login.txt");
		while (file >> fileid >> filepass)
		{
			fileid = security::decryptCaesar(fileid, shift);
			filepass = security::decryptCaesar(filepass, shift);
			if (fileid == username)
			{
				userNotFound = false;
				std::cout << "pasword is: " << filepass << std::endl;
				system("PAUSE");
				break;
			}
		}
		if (userNotFound == true)
		{
			std::cout << "Username not found\n";
			system("PAUSE");
		}
	}
}
