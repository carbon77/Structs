#include "StaticTable.h"
#include "DynamicTable.h"
#include "VectorTable.h"

int main()
{
	int choice;
	std::cout << "Choose task:\n";
	std::cout << "1 - static array\n";
	std::cout << "2 - dynamic array\n";
	std::cout << "3 - std::vector\n" << "-> ";
	std::cin >> choice;

	if (choice == 1)
	{
		testStaticTable();
	}
	else if (choice == 2)
	{
		testDynamicTable();
	}
	else if (choice == 3)
	{
		testVectorTable();
	}
}