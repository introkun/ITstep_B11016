/*Задание 2:
Написать функцию перевода строкового представления двоичного числа(например,
	«0001 0101») в целое десятичное(21) и функцию, которая производит обратное
	преобразование с использованием битовых полей.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct NumberFlags
{
	unsigned char b0 : 1;
	unsigned char b1 : 1;
	unsigned char b2 : 1;
	unsigned char b3 : 1;
	unsigned char b4 : 1;
	unsigned char b5 : 1;
	unsigned char b6 : 1;
	unsigned char b7 : 1;
};

union Number
{
	unsigned char number;
	struct NumberFlags numberFlags;
};

bool checkContentsBinaryNumbers(char* userNumber, int length);
int convertCharValue(char* userNumber, int index);
void printBinaryNumber(union Number* f);

void main()
{
	union Number f;
	char* userNumber = malloc(8);

	int length = 8;
	unsigned int number = 0;
	do
	{
		printf("Enter the number size of 8 bits in the binary representation: ");
		scanf("%s", userNumber);
		length = strlen(userNumber);
	} while (length != 8 || (checkContentsBinaryNumbers(userNumber, length) != true));

	f.numberFlags.b0 = convertCharValue(userNumber, 7);
	f.numberFlags.b1 = convertCharValue(userNumber, 6);
	f.numberFlags.b2 = convertCharValue(userNumber, 5);
	f.numberFlags.b3 = convertCharValue(userNumber, 4);
	f.numberFlags.b4 = convertCharValue(userNumber, 3);
	f.numberFlags.b5 = convertCharValue(userNumber, 2);
	f.numberFlags.b6 = convertCharValue(userNumber, 1);
	f.numberFlags.b7 = convertCharValue(userNumber, 0);

	printf("Decimal number: %i\n", f.number);

	printBinaryNumber(&f);
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

int convertCharValue(char* userNumber, int index)
{
	if (*(userNumber + index) == '0')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void printBinaryNumber(union Number* f)
{
	printf("Binary number: ");
	printf("%i", f->numberFlags.b7);
	printf("%i", f->numberFlags.b6);
	printf("%i", f->numberFlags.b5);
	printf("%i", f->numberFlags.b4);
	printf("%i", f->numberFlags.b3);
	printf("%i", f->numberFlags.b2);
	printf("%i", f->numberFlags.b1);
	printf("%i\n", f->numberFlags.b0);
}