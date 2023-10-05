#pragma once
#include <string>

namespace AppFunctions {
	void login(std::string username, std::string password);
	void registerAccount(std::string username, std::string password);
	void forgotpassword(std::string username);
}