#include "StaticArray.h"

void print(BookCard& bc)
{
	std::cout << "Book: " << bc.name << " - " << bc.author;
	std::cout << ", inventory: " << bc.inventory;

	char s[40];
	strftime(s, 40, "%F", &bc.issueDate);
	std::cout << ", issueDate: " << s;

	strftime(s, 40, "%F", &bc.returnDate);
	std::cout << ", returnDate: " << s;
}

void print(Table& table)
{
	for (int i = 0; i < table.size; i++)
	{
		print(table.data[i]);
		std::cout << "\n";
	}
}

void fillBookCard(BookCard& bc)
{
	std::cout << "\Filling book card:\n";

	int inventory;
	std::cout << "Enter inventory number: ";
	std::cin >> inventory;

	std::cin.ignore();
	std::string author;
	std::cout << "Enter name of the author: ";
	std::getline(std::cin, author);

	std::string name;
	std::cout << "Enter name of the book: ";
	std::getline(std::cin, name);

	time_t t = time(NULL);
	int returnDelay;
	std::cout << "Enter return time(days): ";
	std::cin >> returnDelay;

	tm issueDate;
	tm returnDate;
	
	localtime_s(&issueDate, &t);

	localtime_s(&returnDate, &t);
	returnDate.tm_mday += returnDelay;
	t = mktime(&returnDate);
	localtime_s(&returnDate, &t);

	bc.inventory = inventory;
	bc.author = author;
	bc.name = name;
	bc.issueDate = issueDate;
	bc.returnDate = returnDate;
}

void addBookCard(Table& table, BookCard& bc)
{
	table.data[table.size++] = bc;
}

void removeBookCard(Table& table, int index)
{
	for (int i = index; i < table.size; i++)
	{
		table.data[i] = table.data[i + 1];
	}
	table.size--;
}

void deleteBookCardsByReturnDate(Table& table, time_t& t)
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

void deleteBookCardsByReturnDate(Table& table)
{
	time_t t = time(NULL);
	deleteBookCardsByReturnDate(table, t);
}

int countExpiredBooks(Table& table, time_t t)
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

int countExpiredBooks(Table& table)
{
	time_t t = time(NULL);
	return countExpiredBooks(table, t);
}

void testStaticArray()
{
	int count;
	std::cout << "Enter count books: ";
	std::cin >> count;

	Table table;
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