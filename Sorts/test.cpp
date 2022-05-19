#include "test.h"
#include <chrono>

using std::chrono::milliseconds;
using std::chrono::system_clock;
using std::chrono::duration_cast;
int ns[5] = { 100, 1000, 10000, 100000, 1000000 };


void testInsertSort()
{
	for (int i = 0; i < 5; i++)
	{
		int n = ns[i];
		std::vector<int> arr(n);
		fillArray(arr, n);

		//for (int j = n - 1; j >= 0; j--)
		//	arr.push_back(j);

		auto before = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
		//mergeSort(arr, 0, arr.size());
		// shellSort(arr);
		 insertSort(arr);
		auto after = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

		std::cout << "\nn = " << n << ", time = " << (after - before) / 1000.0;
	}
}