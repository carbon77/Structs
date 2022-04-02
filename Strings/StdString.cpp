#include "StdString.h"

bool isIncreasing(std::string& word)
{
	for (int i = 0; i < word.size() - 1; i++)
	{
		if (word[i] > word[i + 1])
		{
			return false;
		}
	}

	return true;
}

bool needRemove(std::string& word)
{
	int letters[26] = { 0 };

	for (char ch : word)
	{
		letters[ch - 97]++;
	}

	for (int n : letters)
	{
		if (n == 0)
		{
			continue;
		}

		if (n < 2)
		{
			return false;
		}
	}

	return true;
}

void testStdString()
{
	std::string str;
	std::string newStr = "";
	std::cout << "Enter string: ";
	std::getline(std::cin, str);

	std::vector<std::string> words;
	std::string word = "";

	for (int i = 0; i < str.size(); i++)
	{
		char ch = str.at(i);

		if (ch != ',' && ch != ' ')
		{
			word += ch;
		}

		if (ch == ',' || ch == ' ' || i + 1 == str.size())
		{
			if (word != "" && isIncreasing(word))
			{
				words.push_back(word);
			}

			if (word == "" || !needRemove(word))
			{
				newStr += word;
			}
			
			if (ch == ',' || ch == ' ')
			{
				newStr += ch;
			}

			word = "";
			continue;
		}

	}

	if (words.size() != 0)
	{
		std::cout << "Correct words: ";

		for (std::string& w : words)
		{
			std::cout << w << " ";
		}

		std::cout << '\n';
	}

	std::cout << "Modified string: " << newStr;
}