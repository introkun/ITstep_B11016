/*Задание 2
Написать программу, которая содержит функцию, принимающую в качестве аргумента,
указатели на три массива и размер массивов.Функция заносит в массив C суммы
элементов массивов А и В.Размер массивов одинаковый.*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

void fillArrayAorB(int* const array, int const* const size);
void printArray(int const * const array, int const* const size);
void fillArrayC(int const * const arrayA, int const * const arrayB, int * arrayC, int const* const size);

int main()
{
	int arrayA[ARRAY_SIZE];
	int arrayB[ARRAY_SIZE];
	int arrayC[ARRAY_SIZE];

	int size = ARRAY_SIZE;
	
	srand(arrayA);

	printf("ArrayA:");
	fillArrayAorB(arrayA, &size);
	printArray(arrayA, &size);

	printf("\nArrayB:");
	fillArrayAorB(arrayB, &size);
	printArray(arrayB, &size);

	printf("\nArrayC:");
	fillArrayC(arrayA, arrayB, arrayC, &size);
	printArray(arrayC, &size);
	printf("\n");
}

void fillArrayAorB(int* const array, int const* const size)
{
	for (int i = 0; i < *size; i++)
	{
		*(array + i) = rand() % 10 + 1;
	}
}

void printArray(int const * const array, int const* const size)
{
	for (int i = 0; i < *size; i++)
	{
		printf("[%i]\t", *(array + i));
	}
}

void fillArrayC(int const * const arrayA, int const * const arrayB, int* const arrayC, int const* const size)
{
	for (int i = 0; i < *size; i++)
	{
		*(arrayC + i) = *(arrayA + i) + *(arrayB + i);
	}
}