/*Задание 2: Создайте двухмерный массив.Заполните его случайными числами и покажите
на экран.
Пользователь выбирает количество сдвигов и положение(влево, вправо, вверх, вниз).
Выполнить сдвиг массива и показать на экран полученный результат.Сдвиг циклический.
Например, если мы имеем следующий массив
1 2 0 4 5 3
4 5 3 9 0 1
и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
5 3 1 2 0 4
0 1 4 5 3 9*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT_ROW 2
#define COUNT_COLUMN 5

enum Direction
{
	Left = 4,
	Right = 6,
	Up = 8,
	Down = 2
};

void getMatrix(int matrix[2][5], int countRow, int countColumn);
void printMatrix(int matrix[2][5], int countRow, int countColumn);
void moveRight(int matrix[2][5], int countRow, int countColumn);
void moveLeft(int matrix[2][5], int countRow, int countColumn);
void moveUp(int matrix[2][5], int countRow, int countColumn);
void moveDown(int matrix[2][5], int countRow, int countColumn);
void chooseDirection(int matrix[2][5], int countRow, int countColumn);

int main()
{
	int matrix[COUNT_ROW][COUNT_COLUMN];
	
	srand(time(0));

	getMatrix(matrix, COUNT_ROW, COUNT_COLUMN);

	printMatrix(matrix, COUNT_ROW, COUNT_COLUMN);

	chooseDirection(matrix, COUNT_ROW, COUNT_COLUMN);
		
}

void getMatrix(int matrix[2][5], int countRow, int countColumn)
{
	for (int i = 0; i < countRow; i++)
	{
		for (int j = 0; j < countColumn; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

void printMatrix(int matrix[2][5], int countRow, int countColumn)
{
	for (int i = 0; i < countRow; i++)
	{
		for (int j = 0; j < countColumn; j++)
		{
			printf("matrix[%i][%i] = %i\n", i, j, matrix[i][j]);
		}
	}
}

void chooseDirection(int matrix[2][5], int countRow, int countColumn)
{
	enum Direction direction;

	printf("Please, select the direction of the shift: \n");
	printf("Left = 4\nRight = 6\nUp = 8\nDown = 2\n");
	scanf("%i", &direction);

	switch (direction)
	{
	case Left:
		moveLeft(matrix, countRow, countColumn);
		printf("\n");
		printMatrix(matrix, countRow, countColumn);
		break;
	case Right:
		moveRight(matrix, countRow, countColumn);
		printf("\n");
		printMatrix(matrix, countRow, countColumn);
		break;
	case Up:
		moveUp(matrix, countRow, countColumn);
		printf("\n");
		printMatrix(matrix, countRow, countColumn);
		break;
	case Down:
		moveDown(matrix, countRow, countColumn);
		printf("\n");
		printMatrix(matrix, countRow, countColumn);
		break;
	}
}


void moveLeft(int matrix[2][5], int countRow, int countColumn)
{
	int move;
	printf("Please, enter in how you want to move the multidimensional array: ");
	scanf("%i", &move);

	for (int i = 0; i < countRow; i++)
	{
		for (int k = 0; k < move; k++)
		{
			for (int j = 0; j < countColumn; j++)
			{
				int a = matrix[i][countColumn - 1];
				if (j + 1 < countColumn)
				{
					int buff = matrix[i][j];
					matrix[i][j] = matrix[i][j + 1];
					matrix[i][j + 1] = buff;
				}
				else
				{
					matrix[i][j] = a;
				}
			}
		}
	}
}

void moveRight(int matrix[2][5], int countRow, int countColumn)
{
	int move;
	printf("Please, enter in how you want to move the multidimensional array: ");
	scanf("%i", &move);

	for (int i = 0; i < countRow; i++)
	{
		for (int k = 0; k < move; k++)
		{
			for (int j = countColumn - 1; j >= 0; j--)
			{
				int a = matrix[i][0];
				if (j - 1 >= 0)
				{
					int buff = matrix[i][j];
					matrix[i][j] = matrix[i][j - 1];
					matrix[i][j - 1] = buff;
				}
				else
				{
					matrix[i][j] = a;
				}
			}
		}
	}
}

void moveUp(int matrix[2][5], int countRow, int countColumn)
{
	int move;
	printf("Please, enter in how you want to move the multidimensional array: ");
	scanf("%i", &move);
	for (int i = 0; i < countRow; i++)
	{
		int arrayA[COUNT_COLUMN];
		int arrayBuff[COUNT_COLUMN];
		for (int k = 0; k < move; k++)
		{
			for (int j = 0; j < countColumn; j++)
			{
				arrayA[j] = matrix[1][j];
				if (i + 1 < countRow)
				{
					arrayBuff[j] = matrix[i][j];
					matrix[i][j] = matrix[i + 1][j];
					matrix[i + 1][j] = arrayBuff[j];
				}
				else
				{
					matrix[i][j] = arrayA[j];
				}
			}
		}
	}
}

void moveDown(int matrix[2][5], int countRow, int countColumn)
{
	int move;
	printf("Please, enter in how you want to move the multidimensional array: ");
	scanf("%i", &move);
	for (int i = 0; i < countRow; i++)
	{
		int arrayA[COUNT_COLUMN];
		int arrayBuff[COUNT_COLUMN];
		for (int k = 0; k < move; k++)
		{
			for (int j = 0; j < countColumn; j++)
			{
				arrayA[j] = matrix[0][j];
				if (i - 1 >= 0)
				{
					arrayBuff[j] = matrix[i][j];
					matrix[i][j] = matrix[i - 1][j];
					matrix[i - 1][j] = arrayBuff[j];
				}
				else
				{
					matrix[i][j] = arrayA[j];
				}
			}
		}
	}
}