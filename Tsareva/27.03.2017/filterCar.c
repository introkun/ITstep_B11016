/*Задание 2:
Написать программу, которая хранит информацию об автомобиле(марка, модель, цвет
(enum), тип топлива(enum) и год) в динамическом массиве.Пользователь определяет
размерность массива и вводит 5 автомобилей.Реализовать возможность поиска всех
автомобилей младше определенного года.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Color
{
	Red = 1,
	Green,
	Black,
	While,
	Grey
};

enum FuelType
{
	Benzine80 = 1,
	Benzine92,
	Benzine95,
	Gas,
	Diesel
};

struct Car
{
	char* Brand;
	char* Model;
	enum Color Color;
	enum FuelType FuelType;
	int Year;
};

char* getString(char* message, char* st, int maxStringSize);
void cleanInput();
void getInt(char* message, int* value);
void printCarsFilteredByYear(struct Car* cars, int carsCount, int year);

int main()
{
	int countCar = 0;

	printf("Enter the count of car: ");
	scanf("%i", &countCar);
	cleanInput();

	struct Car* car = malloc(sizeof(struct Car) * countCar);

	int i = 0;
	while (i < countCar)
	{
		printf("\n=== Please enter #%i car: ===\n", i + 1);
		car[i].Brand = malloc(30);
		getString("Brand: ", car[i].Brand, 30);
		car[i].Model = malloc(30);
		getString("Model: ", car[i].Model, 30);
		getInt("Year: ", (int*)&car[i].Year);
		getInt("Choose the color:\nRed = 1\nGreen = 2\nBlack = 3\nWhile = 4\nGrey = 5: \n", (int*)&car[i].Color);
		getInt("Choose the fuel type:\nBenzine80 = 1\nBenzine92 = 2\nBenzine95 = 3\nGas = 4\nDiesel = 5: \n",
			(int*)&car[i].FuelType);
		cleanInput();
		i++;
	}

	int sortYear;
	printf("Please, enter the year, from you want sort: \n");
	scanf("%i", &sortYear);

	printCarsFilteredByYear(car, countCar, sortYear);
}

char* getString(char* message, char* st, int maxStringSize)
{
	char* find;

	printf("%s", message);
	char* result = fgets(st, maxStringSize, stdin);
	if (result)
	{
		find = strchr(st, '\n');
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

void cleanInput()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

void getInt(char* message, int* value)
{
	printf("%s", message);
	scanf("%i", value);
}

void printCar(struct Car* car)
{
	printf("Brand:\t%s\n", car->Brand);
	printf("Model:\t%s\n", car->Model);
	printf("FuelType:\t%i\n", car->FuelType);
	printf("Color:\t%i\n", car->Color);
	printf("Year:\t%i\n\n", car->Year);
}

void printCarsFilteredByYear(struct Car* cars, int carsCount, int year)
{
	for (int i = 0; i < carsCount; i++)
	{
		if (cars[i].Year > year)
		{
			printCar(&cars[i]);
		}
	}
}