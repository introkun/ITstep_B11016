/*Задание 1:
Написать функцию перевода строкового представления двоичного числа(например,
	«0001 0101») в целое десятичное(21) и функцию, которая производит обратное
	преобразование с использованием битовых опираций.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkContentsBinaryNumbers(char* userNumber, int length);
int getDecimalInteger(char* userNumber, int length, int* number);
void getBinaryNumber(char* userNumber, int length, int* number);

int main()
{
	char* userNumber = malloc(9);
	int length = 8;
	unsigned int number = 0;
	do
	{
		printf("Enter the number size of 8 bits in the binary representation: ");
		scanf("%s", userNumber);
		length = strlen(userNumber);
	} while (length != 8 || (checkContentsBinaryNumbers(userNumber, length) != true) );

	number = getDecimalInteger(userNumber, length, &number);

	printf("Decimal number: %i\n", number);

	getBinaryNumber(userNumber, length, &number);
	printf("Binary number: %s\n", userNumber);

	free(userNumber);
}

bool checkContentsBinaryNumbers(char* userNumber, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (userNumber[i] != '0' && userNumber[i] != '1')
		{
			printf("The number must contain only 0 or 1\n");
			return false;
		}
		if (i == 7)
		{
			if (userNumber[i] == '0' || userNumber[i] == '1')
			{
				return true;
			}
		}
	}
}

int getDecimalInteger(char* userNumber, int length, int* number)
{
	int j = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		if (userNumber[j] == '1')
		{
			*number |= 1 << i;
		}
		j++;
	}
	return *number;
}

void getBinaryNumber(char* userNumber, int length, int* number)
{
	char j = length;
	for (int i = 0; i < length; i++)
	{
		j--;
		if (*number & 1 << i)
		{
			userNumber[j] = '1';
		}
		else
		{
			userNumber[j] = '0';
		}
	}
}