#include "Dynamic.h"

int findMax(int* arr, int n)
{
	int m = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > m)
		{
			m = arr[i];
		}
	}

	return m;
}

int findMin(int* arr, int n)
{
	int m = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < m)
		{
			m = arr[i];
		}
	}

	return m;
}

void userInput(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		std::cout << i + 1 << " -> ";
		for (int j = 0; j < cols; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}

void randomInput(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void output(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout.width(4);
			std::cout << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

void findRowMin(int** arr, int rows, int cols, int* rowMin)
{
	for (int i = 0; i < rows; i++)
	{
		rowMin[i] = findMin(arr[i], cols);
	}
}

void findColMax(int** arr, int rows, int cols, int* colMax)
{
	for (int i = 0; i < cols; i++)
	{
		int m = arr[0][i];

		for (int j = 1; j < rows; j++)
		{
			if (m < arr[j][i])
			{
				m = arr[j][i];
			}
		}

		colMax[i] = m;
	}
}

int findGraddles(int** arr, int rows, int cols, int** graddles)
{
	int* rowMin = new int[rows];
	int* colMax = new int[cols];

	findRowMin(arr, rows, cols, rowMin);
	findColMax(arr, rows, cols, colMax);

	int max = findMax(rowMin, rows);
	int min = findMin(colMax, cols);

	if (max < min)
	{
		return 0;
	}

	int k = 0;
	for (int i = 0; i < cols; i++)
	{
		if (colMax[i] == max)
		{
			for (int j = 0; j < rows; j++)
			{
				if (rowMin[j] == max)
				{
					graddles[k][0] = j;
					graddles[k][1] = i;
					k++;
				}
			}
		}
	}

	return k;
}

void deleteTwoDimArray(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete arr;
}

void testDynamic()
{
	int rows;
	std::cout << "Rows ->";
	std::cin >> rows;

	int cols;
	std::cout << "Cols ->";
	std::cin >> cols;

	int** arr = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	int inputChoice;
	std::cout << "1 for user input, 2 for random input:";
	std::cin >> inputChoice;

	if (inputChoice == 1)
	{
		userInput(arr, rows, cols);
	}
	else
	{
		randomInput(arr, rows, cols);
	}

	std::cout << "The matrix:\n";
	output(arr, rows, cols);

	int** graddles = new int* [rows * cols];
	for (int i = 0; i < rows * cols; i++)
	{
		graddles[i] = new int[2];
	}

	int count = findGraddles(arr, rows, cols, graddles);
	if (count == 0)
	{
		std::cout << "There are not saddles\n";
		return;
	}

	std::cout << "Saddles: ";
	for (int i = 0; i < count; i++)
	{
		int x = graddles[i][0];
		int y = graddles[i][1];

		std::cout << "(" << x << ", " << y << ") ";
	}

	deleteTwoDimArray(graddles, rows * cols);
	deleteTwoDimArray(arr, rows);
}