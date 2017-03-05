/*Задание 1
Написать функцию, которая получает указатель на статический двумерный массив(3x5) и
его размер.Функция распределяет положительные, отрицательные и нулевые элементы в
3 отдельных массива, указатели на которые также переданы в функцию.*/

#include <stdio.h>

#define COUNT_ROW 3
#define COUNT_COLUMN 5

void printMatrix(int signed const (*matrix)[COUNT_COLUMN], int const* const countRow, int const* const countColumn);
void distributeArray(int signed const (*matrix)[5], int const* const countRow, int const* const countColumn,
	int* arrayPositiveElements, int* arrayNegativeElements, int* arrayNullElements);
void printArray(int const* const array, int const* const column);

int main()
{
	int signed const matrix[COUNT_ROW][COUNT_COLUMN] = { { 2, 0, -6, 4, 0 },{ 0, -1, 6, -3, 0 },{ -2, 5, -8, 3, 0 } };

	int arrayPositiveElements[COUNT_ROW];
	int arrayNegativeElements[COUNT_ROW];
	int arrayNullElements[COUNT_ROW];

	int countRow = COUNT_ROW;
	int countColumn = COUNT_COLUMN;

	printf("Two-dimensional array has elements:\n");
	printMatrix(matrix, &countRow, &countColumn);
	distributeArray(matrix, &countRow, &countColumn, arrayPositiveElements, arrayNegativeElements, arrayNullElements);
	printf("\nPositive elements:\n");
	printArray(arrayPositiveElements, &countColumn);
	printf("\nNegative elements:\n");
	printArray(arrayNegativeElements, &countColumn);
	printf("\nNull elements:\n");
	printArray(arrayNullElements, &countColumn);
}

void printMatrix(int signed const (*matrix)[COUNT_COLUMN], int const* const countRow, int const*  const countColumn)
{
	for (int i = 0; i < *countRow; i++)
	{
		for (int j = 0; j < *countColumn; j++)
		{
			printf("matrix[%i][%i] = %i\n", i, j, *(*(matrix + i) + j));
		}
	}
}

void distributeArray(int signed const (*matrix)[5], int const* const countRow,
	int const* const countColumn, int* arrayPositiveElements, int* arrayNegativeElements, int* arrayNullElements)
{
	int countZero = 0;
	int countPositive = 0;
	int countNegative = 0;
	for (int i = 0; i < *countRow; i++)
	{
		for (int j = 0; j < *countColumn; j++)
		{
			if (*(*(matrix + i) + j) < 0)
			{
				*(arrayNegativeElements + countNegative) = *(*(matrix + i) + j);
				countNegative++;
			}
			if (*(*(matrix + i) + j) > 0)
			{
				*(arrayPositiveElements + countPositive) = *(*(matrix + i) + j);
				countPositive++;
			}
			if (*(*(matrix + i) + j) == 0)
			{
				*(arrayNullElements + countZero) = *(*(matrix + i) + j);
				countZero++;
			}
		}
	}
}

void printArray(int const* const array, int const* const column)
{
	for (int i = 0; i < *column; i++)
	{
		printf("array[%i] = %i\n", i, *(array + i));
	}
}