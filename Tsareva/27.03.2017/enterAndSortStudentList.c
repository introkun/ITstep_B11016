/*Задание 1:
Написать программу, которая дает пользователю ввести 5 фамилий студентов и хранит их
в динамическом массиве, а затем сортирует их по возрастанию.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE_LIST 5

char** allocList(int sizeList);
void allocLastName(char** list, int sizeList);
void addList(char** list, int sizeList);
void sort(char** list, int sizeList);
void printList(char** list, int sizeList);
void deleteMemory(char** list, int sizeList);

int main()
{
	char** list = allocList(SIZE_LIST);

	allocLastName(list, SIZE_LIST);

	addList(list, SIZE_LIST);

	sort(list, SIZE_LIST);

	printList(list, SIZE_LIST);

	deleteMemory(list, SIZE_LIST);
}

char** allocList(int sizeList)
{
	return malloc(sizeList * sizeof(char*));
}

void allocLastName(char** list, int sizeList)
{
	if (list == 0)
	{
		printf("The wrong pointer in function allocLastName. The pointer should't equal NULL\n");
		return 0;
	}
	for (int i = 0; i < sizeList; i++)
	{
		*(list + i) = malloc(256 * sizeof(char));
	}
}

void addList(char** list, int sizeList)
{
	if (list == 0)
	{
		printf("The wrong pointer in function addList. The pointer should't equal NULL\n");
		return 0;
	}
	for (int i = 0; i < sizeList; i++)
	{
		printf("last name %i: \n", i + 1);
		fgets(*(list + i), 256, stdin);
		printf("\n");
	}
}

void sort(char** list, int sizeList)
{
	if (list == 0)
	{
		printf("The wrong pointer in function sort. The pointer should't equal NULL\n");
		return 0;
	}
	char* buff = NULL;
	for (int i = 0; i < sizeList - 1; i++)
	{
		for (int j = 0; j < sizeList - i - 1; j++)
		{
			if (strcmp(*(list + j), *(list + j + 1)) == 1)
			{
				buff = *(list + j);
				*(list + j) = *(list + j + 1);
				*(list + j + 1) = buff;
			}
		}
	}
}

void printList(char** list, int sizeList)
{
	if (list == 0)
	{
		printf("The wrong pointer in function printList. The pointer should't equal NULL\n");
		return 0;
	}
	for (int i = 0; i < sizeList; i++)
	{
		printf("print last name %i: \n", i + 1);
		printf("%s", *(list + i));
	}
}

void deleteMemory(char** list, int sizeList)
{
	if (list == 0)
	{
		printf("The wrong pointer in function deleteMemory\n");
		return 0;
	}
	for (int i = 0; i < sizeList; i++)
	{
		free(*(list + i));
	}

	free(list);
}