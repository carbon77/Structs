#include "searches.h"

bool companySorter(Company& c1, Company& c2)
{
	return c2.id - c1.id > 0;
}

int forceSearch(std::vector<Company>& arr, int key)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr.at(i).id == key)
			return i;
	}
	return -1;
}

int borderSearch(std::vector<Company>& arr, int key)
{
	Company c = { key, "" };
	arr.at(arr.size() - 1) = c;
	int i = 0;

	while (arr.at(i).id != key)
	{
		i++;
	}

	if (i <= arr.size() - 1)
		return i;
	return -1;
}


int fibSearch(std::vector<Company>& arr, int key)
{
	int n = arr.size();
	int fibM2 = 0;
	int fibM1 = 1;
	int fibM = fibM1 + fibM2;

	while (fibM < n)
	{
		fibM2 = fibM1;
		fibM1 = fibM;
		fibM = fibM1 + fibM2;
	}

	int offset = -1;

	while (fibM > 1)
	{
		int i = std::min(offset + fibM2, n - 1);

		if (arr.at(i).id < key)
		{
			fibM = fibM1;
			fibM1 = fibM2;
			fibM2 = fibM - fibM1;
			offset = i;
		}
		else if (arr.at(i).id > key)
		{
			fibM = fibM2;
			fibM1 = fibM1 - fibM2;
			fibM2 = fibM - fibM1;
		}
		else
		{
			return i;
		}
	}

	if (fibM1 && arr.at(offset + 1).id == key)
	{
		return offset + 1;
	}

	return -1;
}


void testSearch()
{
	int n, keyIndex, choose;
	std::cout << "Enter n: ";
	std::cin >> n;

	std::cout << "Enter index of key: ";
	std::cin >> keyIndex;
	
	std::vector<Company> arr(n + 1);

	std::cout << "Choose sort (1 - force, 2 - border, 3 - fibonacci): ";
	std::cin >> choose;

	for (int i = 0; i < n; i++)
	{
		int id = rand() % 1000000;
		Company comp = { id, std::to_string(id) };
		arr.at(i) = comp;
	}

	if (choose == 3)
	{
		std::cout << "\nSorting...";
		std::sort(arr.begin(), arr.end(), companySorter);
	}

	/*for (Company& c : arr)
	{
		std::cout << c.name << " ";
	}*/

	std::cout << "\nSearching...";
	long long before;
	long long after;
	int index;
	int key = arr.at(keyIndex).id;

	if (choose == 1)
	{
		before = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
		index = forceSearch(arr, key);
		after = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	}
	else if (choose == 2)
	{
		before = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
		index = borderSearch(arr, key);
		after = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	}
	else if (choose == 3)
	{
		before = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
		index = fibSearch(arr, key);
		after = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	}

	std::string msg = index == -1 ? "Not found" : "Found";
	Company c = arr.at(index);
	std::cout << std::endl << msg << ": " << arr.at(index).name << ". Time = " << (after - before) / 1000.0 << "ms";
}
