#include <iostream>
#include <vector>

using Array = std::vector<int>;

void fillArray(Array& arr)
{
	std::cout << "Enter " << arr.size() << " elements:\n";

	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << i + 1 << " -> ";
		std::cin >> arr[i];
	}
}

void outputArray(Array& arr)
{
	for (int num : arr)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

int findMaxIndexEven(Array& arr)
{
	int maxIndex = -1;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr.at(i) % 2 == 0)
		{
			if (maxIndex == -1 || arr.at(maxIndex) < arr.at(i))
			{
				maxIndex = i;
			}
		}
	}

	return maxIndex;
}

void vector()
{
	std::cout << "Enter array size: ";

	int n;
	std::cin >> n;

	Array arr = Array(n);

	fillArray(arr);
	outputArray(arr);

	int maxEvenIndex = findMaxIndexEven(arr);
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

	auto iter = arr.begin();
	arr.insert(iter + maxEvenIndex + 1, numForInsert);

	std::cout << "The array: ";
	outputArray(arr);

	iter = arr.begin();

	if (iter + maxEvenIndex != arr.begin()) {
		arr.erase(iter + maxEvenIndex - 1);
		std::cout << "The array after deleting: ";
		outputArray(arr);
	}

}
