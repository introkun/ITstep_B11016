/*Задание 2: Есть стопка оладий различного радиуса.Единственная операция, проводимая с
ними - между любыми двумя суем лопатку и меняем порядок оладий над лопаткой на
обратный.Необходимо за минимальное количество операций таких отсортировать снизу -
вверх по убыванию радиуса.*/

#include <stdio.h>
#include <Windows.h>

#define MUFFIN_COUNT 6

void sortArray(int array[], int count);
void printArray(int array[], int count);

int main()
{
	int arrayPancakes[MUFFIN_COUNT] = { 1, 4, 3, 5, 2, 8, };

	printf("Pancakes stack now:\n");
	printArray(arrayPancakes, MUFFIN_COUNT);

	printf("\nPancakes stack after sort:\n");
	sortArray(arrayPancakes, MUFFIN_COUNT);
	printArray(arrayPancakes, MUFFIN_COUNT);
}

void sortArray(int array[], int count)
{
	for (int i = 0; i < count; i++)
	{
		while (i < count)
		{
			if (i == 0)
			{
				i = 1;
			}
			if (array[i - 1] >= array[i])
			{
			++i; 
			}
			else
			{
				int buff = array[i];
				array[i] = array[i - 1];
				array[i - 1] = buff;
				i--;
			}
		}
	}
}

void printArray(int array[], int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < array[i]; j++)
		{
			printf("%c", 220);
		}
		printf("\n");
		Sleep(1000);
	}
}