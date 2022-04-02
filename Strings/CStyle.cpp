#include "CStyle.h"

void print(char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		std::cout << s[i++];
	}
}

bool isIncreasing(char* s)
{
	int i = 0;
	while (s[i + 1] != '\0')
	{
		if (s[i] > s[i + 1])
		{
			return false;
		}

		i++;
	}

	return true;
}

bool needRemove(char* s)
{
	int letters[26] = { 0 };
	int i = 0;

	while (s[i] != '\0')
	{
		letters[s[i++] - 97]++;
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

std::iostream& operator<<(std::iostream& cout, char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		cout << s[i];
	}

	return cout;
}

void testCStyle()
{
	char str[1024];
	char newStr[1024] = "";
	std::vector<char*> words;

	// Input string
	std::cout << "Enter string: ";
	gets_s(str);
	
	std::cout << "String: " << str << "\n";

	char word[20];
	int j;
	int i = 0;
	int k = 0;

	while (str[i] != '\0')
	{
		j = 0;

		while (str[i] != '\0' && str[i] != ' ' && str[i] != ',')
		{
			word[j++] = str[i++];
		}

		word[j] = '\0';
		if (j == 0)
		{
			newStr[k++] = str[i];
			newStr[k] = '\0';
			i++;
			continue;
		}

		if (isIncreasing(word))
		{
			char* buf = new char[20];
			strcpy_s(buf, 20, word);
			words.push_back(buf);
		}

		if (!needRemove(word))
		{
			strcat_s(newStr, word);
			k += j;
		}
		newStr[k++] = str[i];
		newStr[k] = '\0';

		if (str[i] != '\0')
		{
			i++;
		}
	}

	if (words.size() != 0)
	{
		std::cout << "Correct words: ";

		for (char*& w : words)
		{
			std::cout << w << " ";
		}
	}

	std::cout << "\nModified string: ";
	print(newStr);
}