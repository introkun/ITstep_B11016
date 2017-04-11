//Задание 2:
//Написать функцию, которая определяет, является ли введенное слово анаграммой.

#include <stdio.h>
#include <locale.h>
#include <string.h>

#define STRING_ROW 56

void fillArrayForCompare(char* stringArray, char* stringArrayForCompare);
void verification(char* stringArray, char* stringArrayForCompare);

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Напишите слово, для проверки на палиндром.\n");
	char stringArray[STRING_ROW];
	fgets(stringArray, STRING_ROW, stdin);
	char stringArrayForCompare[STRING_ROW];
	fillArrayForCompare(stringArray, stringArrayForCompare);
}

void fillArrayForCompare(char* stringArray, char* stringArrayForCompare)
{
	int arrayLength = strlen(stringArray) - 1;
	int count = arrayLength - 1;
	for (int i = 0; i < arrayLength; i++)
	{
		stringArrayForCompare[i] = stringArray[count];
		count--;
	}
	stringArrayForCompare[arrayLength] = 0;

	verification(stringArray, stringArrayForCompare);
}

void verification(char* stringArray, char* stringArrayForCompare)
{
	if (strcmp(stringArray, stringArrayForCompare) > 0)
	{
		printf("Это палиндром.\n");
	}
	else
	{
		printf("Это не палиндром.\n");
	}
}

