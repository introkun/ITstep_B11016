/*Задание 1:
Напишите программу поиска факториала числа без использования возвращения значения
из функции факториала(return result;), используйте указатель на переменную с
результатом и передавайте ее в рекурсивную функцию(например, factor(int* result)).*/

#include <stdio.h>

void enterUserNumber(int *userNumber);
void defineFactorial(int userNumber, int* result);

int main()
{
	int userNumber;

	int result = 1;

	enterUserNumber(&userNumber);

	defineFactorial(userNumber, &result);
	
	printf("%i\n", result);
}

void enterUserNumber(int *userNumber)
{
	printf("Enter number for define factorial ");
	scanf("%i", userNumber);
}

void defineFactorial(int userNumber, int* result)
{
	if (userNumber < 2)
	{
		return;
	}
	*result = userNumber * (*result);
	defineFactorial(userNumber - 1, result);
}