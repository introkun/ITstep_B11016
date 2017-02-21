#include <stdio.h>
#include<locale.h>

/*
Напишите программу поиска факториала числа без использования возвращения значения
из функции факториала (return result;), используйте указатель на переменную с
результатом и передавайте ее в рекурсивную функцию (например, factor(int* result)).
*/

void getNumber(int* number);
int printFactorial(int* number);

int main()
{
	setlocale(LC_ALL,"rus");	
	int number = 0;
	getNumber(&number);
	printf("%i\n", printFactorial(&number));

	return 0;
}


void getNumber(int* number)
{
	printf("Введите  значение\n");
	scanf("%i", number);
	
}



int printFactorial(int* number)
{
	
	if (*number <= 1)
	{
		return 1;
	}
	else
	{
		int temp = *number - 1;
		return *number *printFactorial(&temp);
	}
}
