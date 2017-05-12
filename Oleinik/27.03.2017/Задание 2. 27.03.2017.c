//������� 2:
//�������� ���������, ������� ������ ���������� �� ����������(�����, ������, ����
//(enum), ��� �������(enum) � ���) � ������������ �������.������������ ����������
//����������� ������� � ������ 5 �����������.����������� ����������� ������ ����
//����������� ������ ������������� ����.


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
	printf("������� ����������� �������� �����: ");
	scanf("%i", &carQuantity);
	cleanInput();

	struct InfoAboutCar* infoAboutCar = malloc(carQuantity * sizeof(struct InfoAboutCar));
	for (int i = 0; i < carQuantity; i++)
	{
		printf("������� ��������� ������ ��� ������ #%i\n", i + 1);
		printf("��������: ");
		infoAboutCar[i].Name = malloc(30);
		fgets(infoAboutCar[i].Name, 30, stdin);
		printf("������: ");
		infoAboutCar[i].Model = malloc(30);
		fgets(infoAboutCar[i].Model, 30, stdin);
		printf("����: ");
		infoAboutCar[i].color = malloc(30);
		fgets(infoAboutCar[i].color, 30, stdin);
		printf("��� �������: ");
		infoAboutCar[i].fuelType = malloc(30);
		fgets(infoAboutCar[i].fuelType, 30, stdin);
		printf("��� ������������: ");
		infoAboutCar[i].year = malloc(30);
		scanf("%i", &infoAboutCar[i].year);
		cleanInput();
	}

	callMenu(infoAboutCar, carQuantity);

	free(infoAboutCar);
}

void callMenu(struct InfoAboutCar* infoAboutCar, int carQuantity)
{
	printf("��������:\n1. ������� ���������� � ������� �� �����.\n2. ������������� � ������� �� ����� ���������� � �������.\n");
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
	printf("������� ��� ��� ����������: ");
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
	printf("�������� ������: %s", infoAboutCar->Name);
	printf("������: %s", infoAboutCar->Model);
	printf("��� �������: %s", infoAboutCar->fuelType);
	printf("����: %s", infoAboutCar->color);
	printf("���: %i\n", infoAboutCar->year);
}

void cleanInput()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}


