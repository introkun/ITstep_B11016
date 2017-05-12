//Задание 1:
//Написать функцию, которая вставляет в строку в указанную позицию заданный символ

#include <stdio.h>
#include <locale.h>
#include <string.h>

#define STRING_ROW 256

int calcArrayLength(char* stringForChange);
void entreSentence(char* stringForChange);
int chooseLetterNumber(char* stringForChange);
void changeLetter(char* stringForChange);

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Программа, в которой вы вводите предложение и после изменяете в ней любую букву.\n");
	char stringForChange[STRING_ROW];
	entreSentence(stringForChange);
	changeLetter(stringForChange);
}

int calcArrayLength(char* stringForChange)
{
	int arrayLength = 0;
	while (*stringForChange++ != 0)
	{
		arrayLength++;
	}
	return arrayLength - 1;
}


void entreSentence(char* stringForChange)
{
	printf("Введите ваше предложение: ");
	fgets(stringForChange, STRING_ROW, stdin);
}

int chooseLetterNumber(char* stringForChange)
{
	int arrayLength = calcArrayLength(stringForChange);
	printf("Введите номер буквы, которую хотите заменить: ");
	int letterNumber = 0;
	scanf("%i", &letterNumber);
	if (letterNumber > arrayLength)
	{
		printf("Номера с такой буквы нет.\n");
		chooseLetterNumber(stringForChange);
	}
	
}

void changeLetter(char* stringForChange)
{
	int letterNumber = chooseLetterNumber(stringForChange);
	
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);


	printf("Введите букву для замены: ");
	char symbol;
	scanf("%c", &symbol);
	stringForChange[letterNumber - 1] = symbol;
	printf("Измененный массив: %s", stringForChange);
}