#include "StaticArray.h"

void print(StaticTable& table)
{
	for (int i = 0; i < table.size; i++)
	{
		std::cout << table.data[i] << '\n';
	}
}

void addBookCard(StaticTable& table, BookCard& bc)
{
	table.data[table.size++] = bc;
}

void removeBookCard(StaticTable& table, int index)
{
	for (int i = index; i < table.size; i++)
	{
		table.data[i] = table.data[i + 1];
	}
	table.size--;
}

void deleteBookCardsByReturnDate(StaticTable& table, time_t& t)
{
	tm u;
	localtime_s(&u, &t);
	int year = u.tm_year;
	int month = u.tm_mon;
	int day = u.tm_mday;

	for (int i = 0; i < table.size; i++)
	{
		BookCard& bc = table.data[i];
		if (year >= bc.returnDate.tm_year &&
			month >= bc.returnDate.tm_mon && 
			day > bc.returnDate.tm_mon)
		{
			removeBookCard(table, i);
		}
	}
}

void deleteBookCardsByReturnDate(StaticTable& table)
{
	time_t t = time(NULL);
	deleteBookCardsByReturnDate(table, t);
}

int countExpiredBooks(StaticTable& table, time_t t)
{
	int count = 0;
	tm u;
	localtime_s(&u, &t);
	int day = u.tm_mday;
	int month = u.tm_mon;
	int year = u.tm_year;

	for (int i = 0; i < table.size; i++)
	{
		BookCard& bc = table.data[i];
		if (year >= bc.returnDate.tm_year &&
			month >= bc.returnDate.tm_mon &&
			day > bc.returnDate.tm_mon)
		{
			count++;
		}
	}

	return count;
}

int countExpiredBooks(StaticTable& table)
{
	time_t t = time(NULL);
	return countExpiredBooks(table, t);
}

void testStaticArray()
{
	int count;
	std::cout << "Enter count books: ";
	std::cin >> count;

	StaticTable table;
	for (int i = 0; i < count; i++)
	{
		BookCard bc;
		fillBookCard(bc);
		addBookCard(table, bc);
	}

	std::cout << "\n=====\nBooks:\n";
	print(table);
	std::cout << "=====";

	time_t t = time(NULL);
	tm u;
	localtime_s(&u, &t);
	u.tm_mday += 7;
	t = mktime(&u);
	std::cout << "\nExpired: " << countExpiredBooks(table, t) << "\n=====\n";
	deleteBookCardsByReturnDate(table, t);

	std::cout << "Books:\n";
	print(table);
	std::cout << "=====";
}