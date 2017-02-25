/*Домашнее задание
Задание 1: Написать программу «справочник».Создать два одномерных массива.Один
массив хранит номера ICQ, второй – телефонные номера.Реализовать меню для
пользователя :
• Отсортировать по номерам ICQ
• Отсортировать по номерам телефона
• Вывести список пользователей
• Выход*/

#include <stdio.h>
#include <stdlib.h>

#define USERS_COUNT 10

enum Menu
{
	SortForIcq = 1,
	SortForPhoneNumber = 2,
	ShowUsersList = 3,
	ExitFromProgramm = 4
};

void fillArrayNumbersIcqOrPhoneNumbers(int array[], int count);
void sortArrayNumbersIcqOrPhoneNumbers(int array[], int count);
void printArray(int array[], int count);
void printList();
void chooseFromMenu(int numbersIcq[], int phomeNumbers[], int count);

int main()
{
	srand(time(0));

	int numbersIcq[USERS_COUNT];
	int phomeNumbers[USERS_COUNT];
		
	fillArrayNumbersIcqOrPhoneNumbers(numbersIcq, USERS_COUNT);
	fillArrayNumbersIcqOrPhoneNumbers(phomeNumbers, USERS_COUNT);

	printf("You have contact list\n");
	printf("Users ICQ numbers\n");

	printArray(numbersIcq, USERS_COUNT);

	printf("\nUsers phone numbers\n");

	printArray(phomeNumbers, USERS_COUNT);

	chooseFromMenu(numbersIcq, phomeNumbers, USERS_COUNT);
}

void fillArrayNumbersIcqOrPhoneNumbers(int array[], int count)
{

	for (int i = 0; i < count; i++)
	{
		array[i] = 1000000 + rand() % 10000000;
	}
}

void sortArrayNumbersIcqOrPhoneNumbers(int array[], int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int a = array[j];
				array[j] = array[j + 1];
				array[j + 1] = a;
			}
		}
	}
}

void printArray(int array[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%i.  %i\n", i + 1, array[i]);
	}
}

void printList()
{
	printf("1.Masha\n2.Sveta\n3.Oleg\n4.Olga\n5.Sergey\n6.Natasha\n7.Slava\n8.Vera\n9.Kirill\n10.Dima\n");
}

void chooseFromMenu(int numbersIcq[], int phomeNumbers[], int count)
{
	enum Menu menu;

	printf("\nYou can do the next actions:\n1 - Sort ICQ numbers\n2 - Sort phone numbers\n3 - Show users list\n4 - Exit from programm\n");
	scanf("%i", &menu);
	
	switch (menu)
	{
	case SortForIcq:
		sortArrayNumbersIcqOrPhoneNumbers(numbersIcq, count);
		printArray(numbersIcq, count);
		break;
	case SortForPhoneNumber:
		sortArrayNumbersIcqOrPhoneNumbers(phomeNumbers, count);
		printArray(numbersIcq, count);
		break;
	case ShowUsersList:
		printList();
		break;
	case ExitFromProgramm:
		return 1;
	}
}