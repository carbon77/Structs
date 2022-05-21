#include "regex.h"

std::regex regex("�\.([�-��-�]+),");

std::string findCity(std::string& address)
{
	std::smatch m;
	auto begin = address.cbegin();
	auto end = address.cend();

	std::vector<std::string> matches{
		std::sregex_token_iterator {begin, end, regex, 1},
		std::sregex_token_iterator{}
	};

	if (matches.size() == 0)
		return "";
	return matches[0];
}

void testRegex()
{
	std::vector<std::string> tests{
		"123456, �.������, ��.����������, �.25",
		"���������� �������,�.�����������, ��.�������, �.13.",
		"�.������, 123456, ��.����������, �.25"
	};

	for (auto address : tests)
	{
		std::cout << "Text: " << address << "\n";
		std::cout << "City: " << findCity(address) << "\n";
	}
}
