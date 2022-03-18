#include "Static.h"

const int ROWS = 20;
const int COLS = 20;

void findRowMin(int arr[][COLS], int rows, int cols, int rowMin[])
{
	for (int i = 0; i < rows; i++)
	{
		rowMin[i] = *std::min_element(arr[i], arr[i] + rows);
	}
}

void findColMax(int arr[][COLS], int rows, int cols, int colMax[])
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (colMax[i] < arr[j][i])
			{
				colMax[i] = arr[j][i];
			}
		}
	}
}

int findGraddles(int arr[][COLS], int rows, int cols, int graddles[][2])
{
	int rowMin[ROWS], colMax[COLS];

	findRowMin(arr, rows, cols, rowMin);
	findColMax(arr, rows, cols, colMax);

	int max = *std::max_element(rowMin, rowMin + rows);
	int min = *std::min_element(colMax, colMax + cols);

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

void userInput(int arr[][COLS], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << " -> ";

		for (int j = 0; j < m; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}

void randomInput(int arr[][COLS], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num = rand() % 100;
			arr[i][j] = num;
		}
	}
}

void output(int arr[][COLS], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout.width(4);
			std::cout << arr[i][j];
		}

		std::cout << std::endl;
	}
}

void testStatic()
{
	int arr[ROWS][COLS];

	int rows, cols;

	std::cout << "Rows -> ";
	std::cin >> rows;

	std::cout << "Cols -> ";
	std::cin >> cols;

	int inputChoice;
	std::cout << "1 for user input, 2 for random input\n" << "->";
	std::cin >> inputChoice;

	if (inputChoice == 1)
	{
		userInput(arr, rows, cols);
	}
	else if (inputChoice == 2)
	{
		randomInput(arr, rows, cols);
	}

	std::cout << "Your matrix:\n";
	output(arr, rows, cols);

	int graddles[ROWS * COLS][2];
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
}
