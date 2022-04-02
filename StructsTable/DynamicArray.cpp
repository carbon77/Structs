#include "DynamicTable.h"

void print(DynamicTable& table)
{
	for (int i = 0; i < table.size; i++)
	{
		std::cout << table.data[i] << '\n';
	}
}

void addBookCard(DynamicTable& table, BookCard& bc)
{
	if (table.size < table.capacity)
	{
		table.data[table.size++] = bc;
		return;
	}

	BookCard* data = new BookCard[table.size + 1];

	for (int i = 0; i < table.size; i++)
	{
		data[i] = table.data[i];
	}
	data[table.size++] = bc;
	table.capacity++;
	table.data = data;
}

void removeBookCard(DynamicTable& table, int index)
{
	for (int i = index; i < table.size - 1; i++)
	{
		table.data[i] = table.data[i + 1];
	}
	table.size--;
}

void deleteBookCardsByReturnDate(DynamicTable& table, time_t& t)
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

void deleteBookCardsByReturnDate(DynamicTable& table)
{
	time_t t = time(NULL);
	deleteBookCardsByReturnDate(table, t);
}

int countExpiredBooks(DynamicTable& table, time_t t)
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

int countExpiredBooks(DynamicTable& table)
{
	time_t t = time(NULL);
	return countExpiredBooks(table, t);
}

void testDynamicArray()
{
	int size;
	std::cout << "Enter count books: ";
	std::cin >> size;

	DynamicTable table = { 0, size, new BookCard[size] };

	for (int i = 0; i < size; i++)
	{
		BookCard bc;
		fillBookCard(bc);
		addBookCard(table, bc);
	}

	std::cout << "\n=====\nBooks:\n";
	print(table);
	std::cout << "=====";

	// Today + 7 days
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