#include <iostream>

int* createArray(int& n)
{
	std::cout << "Enter array size: ";
	std::cin >> n;

	int* arr = new int[n];
	return arr;
}

void fillArray(int* arr, int n)
{
	std::cout << "Enter " << n << " elements:\n";

	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << " -> ";
		std::cin >> arr[i];
	}
}

int* resizeArray(int* arr, int& n, int newSize)
{
	int* newArr = new int[newSize];

	for (int i = 0; i < (n < newSize ? n : newSize); i++)
	{
		newArr[i] = arr[i];
	}

	n = newSize;
	return newArr;
}

void insertNum(int*& arr, int& n, int value, int index = -1)
{
	arr = resizeArray(arr, n, n + 1);

	if (index == -1 || index >= n)
	{
		arr[n - 1] = value;
		return;
	}

	for (int i = n - 2; i >= index; i--)
	{
		arr[i + 1] = arr[i];
	}

	arr[index] = value;
}

void deleteNum(int*& arr, int& n, int index = -1)
{
	if (index == -1)
	{
		return;
	}

	if (index >= n)
	{
		index = n - 1;
	}

	for (int i = index + 1; i < n; i++)
	{
		arr[i - 1] = arr[i];
	}

	arr = resizeArray(arr, n, n - 1);
}

void outputArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";
}

int findMaxIndexEven(int* arr, int n)
{
	int maxIndex = -1;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0 && arr[maxIndex] < arr[i])
		{
			maxIndex = i;
		}
	}

	return maxIndex;
}

void dynamicArray()
{
	int n;
	int* arr = createArray(n);

	fillArray(arr, n);
	std::cout << "The array: ";
	outputArray(arr, n);

	int maxEvenIndex = findMaxIndexEven(arr, n);
	if (maxEvenIndex == -1)
	{
		std::cout << "There are no even numbers in the array!\n";
		return;
	}
	else
	{
		std::cout << "Index of max even number: " << maxEvenIndex << "\n";
	}

	std::cout << "Enter a number to insert after the max even number: ";
	int numForInsert;
	std::cin >> numForInsert;

	insertNum(arr, n, numForInsert, maxEvenIndex + 1);

	std::cout << "The array after insertion: ";
	outputArray(arr, n);

	deleteNum(arr, n, maxEvenIndex - 1);
	std::cout << "The array after deletion: ";
	outputArray(arr, n);

	delete[] arr;
}
