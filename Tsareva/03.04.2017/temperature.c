/*Тема: Динамическое выделение памяти
	Домашнее задание
	Задание 1 :
	Написать программу, которая получает от пользователя количество дней измерений
	температуры(дата, температура), затем получает эти измерения и записывает их в
	динамический массив.Затем программа спрашивает еще несколько дней измерений и
	программа, используя realloc перевыделяет память.Вывести полученный массив на экран.
	Пример :
	1. Пользователь вводит количество дней – 5
	2. Программа выделяет динамический массив из 5 элементов
	3. Программа спрашивает еще количество дней – 3
	4. Программа перевыделяет динамический массив на 8 элементов(5 + 3)*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct Weather
{
	char* Day;
	float Temperature;
};

void cleanInput();
char* getString(char* string, int size);
void enterTemperatureAndDay(struct Weather* weather, int countDay, int* filledDays);
void printWeather(struct Weather* weather, int countDay);

int main()
{
	printf("Please, enter the quantity of day, that you want to fill of temperatures: ");
	int countDay;
	scanf("%i", &countDay);
	cleanInput();
	int filledDays = 0;

	struct Weather* weather = malloc(countDay * sizeof(struct Weather));

	enterTemperatureAndDay(weather, countDay, &filledDays);
	printWeather(weather, countDay);

	int countNewDays;
	printf("Please, enter the quantity of day, that you want to refill your list of temperature: ");
	scanf("%i", &countNewDays);
	cleanInput();

	struct Weather* weatherNew = realloc(weather,(countDay + countNewDays) * sizeof(struct Weather));
	enterTemperatureAndDay(weather, countDay + countNewDays, &filledDays);
	printWeather(weather, countDay + countNewDays);

	for (int i = 0; i < countDay + countNewDays; i++)
	{
		free(weatherNew[i].Day);
	}
	free(weatherNew);
}

void enterTemperatureAndDay(struct Weather* weather, int countDay, int* filledDays)
{
	int i;
	for (i = *filledDays; i < countDay; i++)
	{
		weather[i].Day = malloc(30);
		printf("Please, enter the day:\n");
		getString(weather[i].Day, 30);
		printf("Enter temperature:\n");
		scanf("%f", &weather[i].Temperature);
		cleanInput();
	}
	*filledDays = i;
	printf("%i", *filledDays);
}

void printWeather(struct Weather* weather, int countDay)
{
	for (int i = 0; i < countDay; i++)
	{
		printf("%s temperature has been %.2f\n", weather[i].Day, weather[i].Temperature);
	}
}

void cleanInput()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

char* getString(char* st, int maxStringSize)
{
	char* find;

	char* result = fgets(st, maxStringSize, stdin);
	if (result)
	{
		find = strchr(result, '\n');
		if (find)
		{
			*find = 0;
		}
		else
		{
			cleanInput();
		}
	}
	return result;
}