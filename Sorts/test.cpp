#include "test.h"
#include <chrono>

using std::chrono::milliseconds;
using std::chrono::system_clock;
using std::chrono::duration_cast;
int ns[5] = { 100, 1000, 10000, 100000, 1000000 };


void testSort()
{
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;

	std::vector<int> arr;
	fillArray(arr, n);

	int choose;
	std::cout << "Choose sort (1 - insert, 2 - shell, 3 - merge): ";
	std::cin >> choose;

	std::cout << "Initial array: ";
	printArray(arr);

	if (choose == 1)
		insertSort(arr);
	else if (choose == 2)
		shellSort(arr);
	else
		mergeSort(arr, 0, arr.size());

	std::cout << "\nSorted array: ";
	printArray(arr);

	/*for (int i = 0; i < 5; i++)
	{
		int n = ns[i];
		std::vector<int> arr(n);
		fillArray(arr, n);

		auto before = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
		//mergeSort(arr, 0, arr.size());
		// shellSort(arr);
		 insertSort(arr);
		auto after = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

		std::cout << "\nn = " << n << ", time = " << (after - before) / 1000.0;
	}*/
}