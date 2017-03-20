/*Задание 2:
Используя указатель на массив целых чисел, изменить порядок следования элементов
массива на противоположный.Использовать в программе арифметику указателей для
продвижения по массиву, а также оператор разыменования.*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 6

void fillArray(int* array, int count);
void printArray(int* array, int count);
void changeSequenceArrayToOpposite(int* array, int count);

int main()
{
	int array[ARRAY_SIZE];

	srand(array);

	fillArray(array, ARRAY_SIZE);
	printf("Original array:\n");
	printArray(array, ARRAY_SIZE);

	changeSequenceArrayToOpposite(array, ARRAY_SIZE);
	printf("\nArray after changes the sequence of elements to opposite:\n");
	printArray(array, ARRAY_SIZE);
}

void fillArray(int* array, int count)
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
		printf("Array[%i] = %i\n", i, *(array + i));
	}
}

void changeSequenceArrayToOpposite(int* array, int count)
{
	int arrayBuff[ARRAY_SIZE];

	for (int i = 0; i < count; i++)
	{
		*(arrayBuff + i) = *(array + i);
	}
	for (int i = 0; i < count; i++)
	{
		*(array + i) = arrayBuff[count - 1- i];
	}
}