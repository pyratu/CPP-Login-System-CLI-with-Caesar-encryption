#pragma once
#include <string>

namespace security {
	std::string encryptCaesar(std::string text, int x);
	std::string decryptCaesar(std::string text, int x);
}