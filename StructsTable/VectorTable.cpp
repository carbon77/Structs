#include "VectorTable.h"

std::ostream& operator<<(std::ostream& cout, VectorTable& table)
{
	for (BookCard& bc : table)
	{
		std::cout << bc << '\n';
	}

	return cout;
}

void deleteBookCardsByReturnDate(VectorTable& table, time_t& t)
{
	tm u;
	localtime_s(&u, &t);
	int year = u.tm_year;
	int month = u.tm_mon;
	int day = u.tm_mday;

	for (int i = table.size() - 1; i >= 0; i--)
	{
		BookCard& bc = table.at(i);
		if (year >= bc.returnDate.tm_year &&
			month >= bc.returnDate.tm_mon &&
			day > bc.returnDate.tm_mon)
		{
			table.erase(table.begin() + i);
		}
	}
}

void deleteBookCardsByReturnDate(VectorTable& table)
{
	time_t t = time(NULL);
	deleteBookCardsByReturnDate(table, t);
}

int countExpiredBooks(VectorTable& table, time_t t)
{
	int count = 0;
	tm u;
	localtime_s(&u, &t);
	int day = u.tm_mday;
	int month = u.tm_mon;
	int year = u.tm_year;

	for (int i = 0; i < table.size(); i++)
	{
		BookCard& bc = table.at(i);
		if (year >= bc.returnDate.tm_year &&
			month >= bc.returnDate.tm_mon &&
			day > bc.returnDate.tm_mon)
		{
			count++;
		}
	}

	return count;
}

int countExpiredBooks(VectorTable& table)
{
	time_t t = time(NULL);
	return countExpiredBooks(table, t);
}

void testVectorTable()
{
	int size;
	std::cout << "Enter count of books: ";
	std::cin >> size;

	VectorTable table;

	for (int i = 0; i < size; i++)
	{
		BookCard bc;
		fillBookCard(bc);
		table.push_back(bc);
	}

	std::cout << "\n=====\nBooks:\n" << table << "=====";

	// Today + 7 days
	time_t t = time(NULL);
	tm u;
	localtime_s(&u, &t);
	u.tm_mday += 7;
	t = mktime(&u);

	std::cout << "\nExpired: " << countExpiredBooks(table, t) << "\n=====\n";
	deleteBookCardsByReturnDate(table, t);

	std::cout << "Books:\n" << table << "=====";
}