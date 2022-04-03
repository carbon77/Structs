#include "sort.h"

std::ostream& operator<<(std::ostream& cout, std::vector<int> arr)
{
	for (int num : arr)
	{
		cout << num << " ";
	}

	return cout;
}

void merge(std::vector<int>& arr, int left, int middle, int right)
{
	std::vector<int> temp;

	int l = left;
	int r = middle;

	while (l < middle && r < right)
	{
		if (arr[l] < arr[r])
		{
			temp.push_back(arr[l++]);
		}
		else
		{
			temp.push_back(arr[r++]);
		}
	}

	while (l < middle)
	{
		temp.push_back(arr[l++]);
	}

	while (r < right)
	{
		temp.push_back(arr[r++]);
	}

	for (int i = left; i < right; i++)
	{
		arr[i] = temp[i - left];
	}
}

int mergeSort(std::vector<int>& arr, int start, int end)
{
	if (end - start == 1)
	{
		return 1;
	}

	int deep = 1;
	int middle = (start + end) / 2;
	int leftDeep = mergeSort(arr, start, middle);
	int rightDeep = mergeSort(arr, middle, end);
	
	deep += leftDeep > rightDeep ? leftDeep : rightDeep;

	merge(arr, start, middle, end);

	return deep;
}

int mergeSort(std::vector<int>& arr)
{
	return mergeSort(arr, 0, arr.size());
}

void testMergeSort()
{
	srand(time(NULL));
	int n;
	std::cout << "Enter N: ";
	std::cin >> n;

	std::vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		arr.push_back(rand() % 100);
	}

	std::cout << "Generated array: " << arr;
	int deep = mergeSort(arr);
	std::cout << "\n\nSorted array: " << arr;
	std::cout << "\nDeep: " << deep;
}