/*Задание 2:
Напишите программу возведения чисел в степень, используйте указатели для передачи
результирующего значения в функцию и из нее.Числа необходимо получать от
пользователя.*/

#include <stdio.h>

void enterUserNumber(int *userNumber, int* degree);
void calculateUserNumberInDegree(int* userNumber, int* degree, long long* result);
void printResult(int* userNumber, int* degree, long long* result);

int main()
{
	int userNumber;
	int degree;
	long long result;

	enterUserNumber(&userNumber, &degree);

	calculateUserNumberInDegree(&userNumber, &degree, &result);

	printResult(&userNumber, &degree, &result);
}

void enterUserNumber(int* userNumber, int* degree)
{
	printf("Please, enter the number that you want to build in a degree: ");
	scanf("%i", userNumber);

	printf("Please, enter degree (only a positive value): ");
	scanf("%i", degree);
}

void calculateUserNumberInDegree(int* userNumber, int* degree, long long* result)
{
	if (*degree == 0)
	{
		*result = 1;
	}
	else if (*degree == 1)
	{
		*result = *userNumber * 1;
	}
	else
	{
		for (int i = 0; i < *degree - 1; i++)
		{
			if (i == 0)
			{
				*result = *userNumber * *userNumber;
			}
			else
			{
				*result = *result * *userNumber;
			}
		}
	}
}

void printResult(int* userNumber, int* degree, long long* result)
{
	printf("Number %i in degree %i = %lld\n", *userNumber, *degree, *result);
}