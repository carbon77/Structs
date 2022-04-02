#include "BookCard.h"

std::ostream& operator<<(std::ostream& cout, BookCard& bc)
{
	std::cout << "Book: " << bc.name << " - " << bc.author;
	std::cout << ", inventory: " << bc.inventory;

	char s[40];
	strftime(s, 40, "%F", &bc.issueDate);
	std::cout << ", issueDate: " << s;

	strftime(s, 40, "%F", &bc.returnDate);
	std::cout << ", returnDate: " << s;

	return cout;
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