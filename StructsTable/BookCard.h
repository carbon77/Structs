#pragma once

#include <iostream>
#include <string>
#include <ctime>

struct BookCard
{
	int inventory;
	std::string author;
	std::string name;
	std::tm issueDate;
	std::tm returnDate;
};

std::ostream& operator<<(std::ostream& cout, BookCard& bc);
void fillBookCard(BookCard& bc);