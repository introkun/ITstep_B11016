/* 1: Напишите программу, которая создает двухмерный массив и заполняет его по
следующему принципу : пользователь вводит число(например, 3) первый элемент массива
принимает значение этого числа, последующий элемент массива принимает значение
этого числа умноженного на 2 (т.е. 6 для нашего примера), третий элемент массива
предыдущий элемент умноженный на 2 (т.е. 6 * 2 = 12 для нашего примера).Созданный
массив вывести на экран*/

#include <stdio.h>

#define COUNT_ROW 2
#define COUNT_COLUMN 8

void getArray(int matrix[2][8], int countRow, int countColumn);
void printArray(int matrix[2][8], int countRow, int countColumn);

int main()
{
	int matrix[COUNT_ROW][COUNT_COLUMN];

	getArray(matrix, COUNT_ROW, COUNT_COLUMN);

	printArray(matrix, COUNT_ROW, COUNT_COLUMN);
}

void getArray(int matrix[2][8], int countRow, int countColumn)
{
	int userNumber;
	int summ = 0;

	printf("Please, enter the number from 1 to 10 from which you want to begin a two-dimensional array: ");
	scanf("%i", &userNumber);

	for (int i = 0; i < countRow; i++)
	{
		for (int j = 0; j < countColumn; j++)
		{
			if (j == 0 && i == 0)
			{
				matrix[i][j] = userNumber;
				summ = userNumber;
			}
			else
			{
				summ = summ * 2;
				matrix[i][j] = summ;
			}
		}
	}
}

void printArray(int matrix[2][8], int countRow, int countColumn)
{
	for (int i = 0; i < countRow; i++)
	{
		for (int j = 0; j < countColumn; j++)
		{
			printf("matrix[%i][%i] = %i\n", i, j, matrix[i][j]);
		}
	}
}