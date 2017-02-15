//Задание 1: В одномерном массиве, заполненном случайными числами, определить
//минимальный и максимальный элементы.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int funciaDlaOpredeleniaMaxChislaIsMassiva(int razmerMassivaIOblastiRandoma);
int funciaDlaOpredeleniaMinChislaIsMassiva(int razmerMassivaIOblastiRandoma);

int odnomerniiMassivSSlychainimiChislami[10];

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	
	printf("Программа заполнит массив случайными числами. Размер массива задаёте вы. Также, числовой диапозон выдачи случайных \nчисел задаётся от размера массива\nЗадайте размерноссть массива: ");
	int razmerMassivaIOblastiRandoma;
	scanf("%i", &razmerMassivaIOblastiRandoma);
	for (int i = 0; i < razmerMassivaIOblastiRandoma; i++)
	{
		odnomerniiMassivSSlychainimiChislami[i] = rand() % (razmerMassivaIOblastiRandoma + 1);
		printf("Число из массива №%i: %i\n", i+1, odnomerniiMassivSSlychainimiChislami[i]);
	}

	funciaDlaOpredeleniaMaxChislaIsMassiva(razmerMassivaIOblastiRandoma);
	printf("Максимальное число из массива %i.\n", (razmerMassivaIOblastiRandoma));

	funciaDlaOpredeleniaMinChislaIsMassiva(razmerMassivaIOblastiRandoma, odnomerniiMassivSSlychainimiChislami);
	printf("Минимальное число из массива %i.\n", funciaDlaOpredeleniaMinChislaIsMassiva(razmerMassivaIOblastiRandoma));
}

int funciaDlaOpredeleniaMaxChislaIsMassiva(int razmerMassivaIOblastiRandoma)
{

	int maxChisloIsMassiva = odnomerniiMassivSSlychainimiChislami[0];
	for (int i = 0; i < razmerMassivaIOblastiRandoma; i++)
	{
		if (maxChisloIsMassiva < odnomerniiMassivSSlychainimiChislami[i])
		{
			maxChisloIsMassiva = odnomerniiMassivSSlychainimiChislami[i];
		}
	}
	return maxChisloIsMassiva;
}

int funciaDlaOpredeleniaMinChislaIsMassiva(int razmerMassivaIOblastiRandoma)
{
	int minChisloIsMassiva = odnomerniiMassivSSlychainimiChislami[0];
	for (int i = 0; i < razmerMassivaIOblastiRandoma; i++)
	{
		if (minChisloIsMassiva > odnomerniiMassivSSlychainimiChislami[i])
		{
			minChisloIsMassiva = odnomerniiMassivSSlychainimiChislami[i];
		}
	}
	return minChisloIsMassiva;
}