/*Задание 1:
Используя два указателя на массив целых чисел, скопировать один массив в другой.
Использовать в программе арифметику указателей для продвижения по массиву, а также
оператор разыменования.*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

void fillArrayA(int* array, int count);
void printArray(int* array, int count);
void fillArrayB(int* arrayA, int* arrayB, int count);

int main()
{
	int arrayA[ARRAY_SIZE];
	int arrayB[ARRAY_SIZE];

	srand(arrayA);

	fillArrayA(arrayA, ARRAY_SIZE);
	printf("Array first:\n");
	printArray(arrayA, ARRAY_SIZE);

	fillArrayB(arrayA, arrayB, ARRAY_SIZE);
	printf("\nArray second:\n");
	printArray(arrayB, ARRAY_SIZE);
}

void fillArrayA(int* array, int count)
{
	for (int i = 0; i < count; i++)
	{
		*(array + i) = rand() % 10;
	}
}

void printArray(int* array, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("array[%i] = %i\n", i, *(array + i));
	}
}

void fillArrayB(int* arrayA, int* arrayB, int count)
{
	for (int i = 0; i < count; i++)
	{
		*(arrayB + i) = *(arrayA + i);
	}
}