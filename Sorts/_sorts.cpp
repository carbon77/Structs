#include "sorts.h"


void printArray(std::vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr.at(i);

		if (i != arr.size() - 1)
			std::cout << " ";
	}
}


void fillArray(std::vector<int>& arr, int n)
{
	for (int i = 0; i < n; i++) {
		arr.push_back(rand() % 100);
	}
}


void insertSort(std::vector<int>& arr)
{
	for (int j = 1; j < arr.size(); j++)
	{
		int key = arr[j];
		int i = j - 1;

		while (i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i--;
		}

		arr[i + 1] = key;
	}
}

void shellSort(std::vector<int>& arr)
{
	for (int d = arr.size() / 2; d > 0; d /= 2)
	{
		for (int i = d; i < arr.size(); i++)
		{
			for (int j = i - d; j >= 0 && arr[j] > arr[j + d]; j -= d)
			{
				int temp = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = temp;
			}
		}
	}
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

void mergeSort(std::vector<int>& arr, int start, int end)
{
	if (end - start == 1)
	{
		return;
	}

	int middle = (start + end) / 2;
	mergeSort(arr, start, middle);
	mergeSort(arr, middle, end);

	merge(arr, start, middle, end);
}
