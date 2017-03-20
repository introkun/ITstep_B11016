/*	Задание 1
Написать программу, которая содержит функцию Action, принимающую в качестве
аргумента, указатели на два массива(А и В) и размеры массивов, а также указатель на
функцию.
Пользователю отображается меню, в котором он может выбрать max, min, avg.
Если выбран max - передается указатель на функцию, которая ищет максимум, если
выбран min - передается указатель на функцию, которая ищет минимум, если выбран avg -
передается указатель на функцию, которая ищет среднее.
Возвращаемое значение функции Action результат выбора пользователя max, min, avg*/

#include <stdio.h>

#define ARRAY_SIZE 5

typedef void(*ACTION)(int*, int*, int);

enum UserChoose
{
	Min = 1,
	Max = 2,
	Average = 3
};

void modifyArray(int* arrayA, int* arrayB, int size,
	ACTION findMin,
	ACTION findMax,
	ACTION findAverage)
{
	enum UserChoose userChoose;
	printf("For finding min enter 1, max enter 2, average enter 3\n");
	scanf("%i", &userChoose);
	switch (userChoose)
	{
	case Min:
		printf("The minimal value of arrays A and B: ");
		findMin(arrayA, arrayB, size);
		break;
	case Max:
		printf("The maximal value of arrays A and B: ");
		findMax(arrayA, arrayB, size);
		break;
	case Average:
		printf("The average value of arrays A and B: ");
		findAverage(arrayA, arrayB, size);
		break;
	}
}

void findMin(int* arrayA, int* arrayB, int arraySize)
{
	int min = *arrayA;
	for (int i = 0; i < arraySize; i++)
	{
		if (min > *(arrayA + i))
		{
			min = *(arrayA + i);
		}
	}
	for (int i = 0; i < arraySize; i++)
	{
		if (min > *(arrayB + i))
		{
			min = *(arrayB + i);
		}
	}
	printf("%i\n", min);
}

void findMax(int* arrayA, int* arrayB, int arraySize)
{
	int max = *arrayA;
	for (int i = 0; i < arraySize; i++)
	{
		if (max < *(arrayA + i))
		{
			max = *(arrayA + i);
		}
	}
	for (int i = 0; i < arraySize; i++)
	{
		if (max < *(arrayB + i))
		{
			max = *(arrayB + i);
		}
	}
	printf("%i\n", max);
}

void findAverage(int* arrayA, int* arrayB, int arraySize)
{
	float sum = 0;
	for (int i = 0; i < arraySize; i++)
	{
		sum += *(arrayA + i);
	}
	for (int i = 0; i < arraySize; i++)
	{
		sum += *(arrayB + i);
	}
	printf("%.2f\n", sum / ((float)(arraySize) * 2));
}

void fillArray(int* array, int* arraySize)
{
	for (int i = 0; i < *arraySize; i++)
	{
		*(array + i) = rand() % 10;
	}
}

void printArray(int* array, int* arraySize)
{
	for (int i = 0; i < *arraySize; i++)
	{
		printf("array[%i] = %i\n", i, *(array + i));
	}
}

void main()
{
	int arrayA[ARRAY_SIZE];
	int arrayB[ARRAY_SIZE];

	int arraySize = ARRAY_SIZE;

	srand(arrayA);

	fillArray(arrayA, &arraySize);
	printf("Array A:\n");
	printArray(arrayA, &arraySize);
	fillArray(arrayB, &arraySize);
	printf("Array B:\n");
	printArray(arrayB, &arraySize);

	modifyArray(arrayA, arrayB, ARRAY_SIZE, findMin, findMax, findAverage);
}