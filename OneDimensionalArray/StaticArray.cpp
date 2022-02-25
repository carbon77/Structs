#include <iostream>

const int N = 100;

void outputArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";
}

void inputArray(int arr[], int n)
{
	std::cout << "Enter " << n << " elements:\n";

	for (int i = 0; i < n; i++) {
		std::cout << i + 1 << " -> ";
		std::cin >> arr[i];
	}
}

int findMaxEvenIndex(int arr[], int n)
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

void insertNum(int arr[], int& n, int index, int value)
{
	for (int i = n - 1; i >= index; i--)
	{
		if (i < N - 1)
		{
			arr[i + 1] = arr[i];
		}
	}

	arr[index] = value;
	n++;
}

void deleteNum(int arr[], int& n, int index)
{
	if (index < 0 || index >= N)
	{
		return;
	}

	for (int i = index + 1; i < n; i++) {
		arr[i - 1] = arr[i];
	}

	n--;
}

void staticArray()
{
	int arr[N] = { 0 };
	int n;

	do
	{
		std::cout << "Enter array size: ";
		std::cin >> n;

		if (n < 0 || n > N)
		{
			std::cout << "Incorrect size!\n";
		}
	} while (n < 0 || n > N);

	inputArray(arr, n);

	std::cout << "The array: ";
	outputArray(arr, n);

	int maxEvenIndex = findMaxEvenIndex(arr, n);
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

	insertNum(arr, n, maxEvenIndex + 1, numForInsert);

	std::cout << "The array: ";
	outputArray(arr, n);

	deleteNum(arr, n, maxEvenIndex - 1);

	std::cout << "The array after deleting: ";
	outputArray(arr, n);
}