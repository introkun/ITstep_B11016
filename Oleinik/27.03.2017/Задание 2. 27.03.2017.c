//Задание 2:
//Написать программу, которая хранит информацию об автомобиле(марка, модель, цвет
//(enum), тип топлива(enum) и год) в динамическом массиве.Пользователь определяет
//размерность массива и вводит 5 автомобилей.Реализовать возможность поиска всех
//автомобилей младше определенного года.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>



enum Menu
{
	PrintStruct = 1,
	SortByYearAndPrint
};

struct InfoAboutCar
{
	char* Name;
	char* Model;
	char* color;
	char* fuelType;
	int year;

};

void cleanInput();
void callMenu(struct InfoAboutCar* infoAboutCar, int carQuantity);
void sortByYear(struct InfoAboutCar* infoAboutCar, int carQuantity);
void printCar(struct InfoAboutCar* infoAboutCar);

int main()
{
	setlocale(LC_ALL, "Rus");

	int carQuantity;
	printf("Задайте колличество вносимых машин: ");
	scanf("%i", &carQuantity);
	cleanInput();

	struct InfoAboutCar* infoAboutCar = malloc(carQuantity * sizeof(struct InfoAboutCar));
	for (int i = 0; i < carQuantity; i++)
	{
		printf("Введите следующие данные для машины #%i\n", i + 1);
		printf("Название: ");
		infoAboutCar[i].Name = malloc(30);
		fgets(infoAboutCar[i].Name, 30, stdin);
		printf("Модель: ");
		infoAboutCar[i].Model = malloc(30);
		fgets(infoAboutCar[i].Model, 30, stdin);
		printf("Цвет: ");
		infoAboutCar[i].color = malloc(30);
		fgets(infoAboutCar[i].color, 30, stdin);
		printf("Тип топлива: ");
		infoAboutCar[i].fuelType = malloc(30);
		fgets(infoAboutCar[i].fuelType, 30, stdin);
		printf("Год производства: ");
		infoAboutCar[i].year = malloc(30);
		scanf("%i", &infoAboutCar[i].year);
		cleanInput();
	}

	callMenu(infoAboutCar, carQuantity);

	free(infoAboutCar);
}

void callMenu(struct InfoAboutCar* infoAboutCar, int carQuantity)
{
	printf("Выберите:\n1. Вывести информацию о машинах на экран.\n2. Отсортировать и вывести на экран информацию о машинах.\n");
	enum Menu menu;
	scanf("%i", &menu);
	switch (menu)
	{
	case PrintStruct:
		for (int i = 0; i < carQuantity; i++)
		{
			printCar(&infoAboutCar[i]);
		}
		break;
	case SortByYearAndPrint:
		sortByYear(infoAboutCar, carQuantity);
		break;
	default:
		break;
	}

	
}

void sortByYear(struct InfoAboutCar* infoAboutCar, int carQuantity)
{
	int yearForSort;
	printf("Введите год для фильтровки: ");
	scanf("%i", &yearForSort);
	for (int i = 0; i < carQuantity; i++)
	{
		if (infoAboutCar[i].year > yearForSort)
		{
			printCar(&infoAboutCar[i]);
		}
	}
}

void printCar(struct InfoAboutCar* infoAboutCar)
{
	printf("Название бренда: %s", infoAboutCar->Name);
	printf("Модель: %s", infoAboutCar->Model);
	printf("Тип топлива: %s", infoAboutCar->fuelType);
	printf("Цвет: %s", infoAboutCar->color);
	printf("Год: %i\n", infoAboutCar->year);
}

void cleanInput()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}


