/*	Задание 1 :
Написать программу, которая дает пользователю вести домашнюю бухгалтерию.В начале
программа спрашивает текущий баланс счета.Затем программа выводит меню :
1. Снять со счета
2. Положить на счет
3. Вывести на экран список транзакций
4. Вывести баланс
5. Выход
Сумма вводится как вещественное число(BYN).К каждой транзакции можно писать
комментарий с указанием типа / содержания транзакции.
Используйте структуры и динамические массивы*/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define COUNT_STRUCT 100

enum Menu
{
	Pay = 1,
	RefillBalans,
	PrintTransaction,
	ShowBalans,
	Exit
};

struct Transaction
{
	float Sum;
	char* To;
	char* Reason;
};

void cleanInput();
void chooseOperation(struct Transaction* transactions, enum Menu* menu, int* countString);
void pay(struct Transaction* transactions, int* countTransaction);
void refillBalans(struct Transaction* transactions, int* countTransaction);
char* getString(char* st, int maxStringSize);
void printTransactions(struct Transaction* transactions, int count);
float countBalans(struct Transaction* transactions, int size);

int main()
{
	struct Transaction* transactions = calloc(COUNT_STRUCT, COUNT_STRUCT * sizeof(struct Transaction));
	enum Menu menu;
	int countTransaction = 1;

	printf("Enter balans: \n");
	scanf("%f", &transactions[0].Sum);

	transactions[0].To = NULL;
	transactions[0].Reason = NULL;

	chooseOperation(transactions, &menu, &countTransaction);
}

void chooseOperation(struct Transaction* transactions, enum Menu* menu, int* countTransaction)
{
	int a = 1;
	while (a)
	{
		printf("\nChoose the operation: \n");
		printf("1 - pay\n2 - refill balans\n3 - print transaction\n4 - show balans\n5 - exit\n");
		scanf("%i", menu);

		float totalSum = 0;

		switch (*menu)
		{
		case Pay:
			if (*countTransaction < COUNT_STRUCT)
			{
				pay(transactions, countTransaction);
				*countTransaction = *countTransaction + 1;
			}
			else
			{
				printf("You don't have any transaction");
			}
			break;
		case RefillBalans:
			if (*countTransaction < COUNT_STRUCT)
			{
				refillBalans(transactions, countTransaction);
				*countTransaction = *countTransaction + 1;
			}
			else
			{
				printf("You don't have any transaction");
			}
			break;
		case PrintTransaction:
			printTransactions(transactions, *countTransaction);
			break;
		case ShowBalans:
			totalSum = countBalans(transactions, *countTransaction);
			printf("Balans = %.2f\n", totalSum);
			break;
		case Exit:
			a = 0;
			break;
		}
	}
}

void pay(struct Transaction* transactions, int* countTransaction)
{
	float totalSum = countBalans(transactions, *countTransaction);
	float buff;
	printf("Enter sum: \n");
	scanf("%f", &buff);
	do
	{
		printf("Youf sum (%.2f) more that balans (%.2f): \n", buff, totalSum);
		scanf("%f", &buff);
	} while (buff > totalSum);
	
	transactions[*countTransaction].Sum = -buff;
	cleanInput();

	printf("Enter the organization, that you want pay: ");
	transactions[*countTransaction].To = malloc(30);
	getString(transactions[*countTransaction].To, 30);

	printf("Enter the reason, that you want pay: ");
	transactions[*countTransaction].Reason = malloc(30);
	getString(transactions[*countTransaction].Reason, 30);
}

void refillBalans(struct Transaction* transactions, int* countTransaction)
{
	printf("Enter balans: \n");
	scanf("%f", &transactions[*countTransaction].Sum);
	transactions[*countTransaction].To = malloc(30);
	transactions[*countTransaction].To = NULL;
	transactions[*countTransaction].Reason = malloc(30);
	transactions[*countTransaction].Reason = NULL;
}

void printTransactions(struct Transaction* transactions, int count)
{
	for (int i = 1; i < count; i++)
	{
		printf("Sum\tOrganization\tReason\n");
		printf("%.2f\t| %s\t\t| %s\n", transactions[i].Sum,
			transactions[i].To ? transactions[i].To : "-",
			transactions[i].Reason ? transactions[i].Reason : "-");
	}
}

float countBalans(struct Transaction* transactions, int size)
{
	float totalSum = 0;
	for (int i = 0; i < size; i++)
	{
		totalSum = transactions[i].Sum + totalSum;
	}
	return totalSum;
}

void cleanInput()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

char* getString(char* st, int maxStringSize)
{
	char* find;

	char* result = fgets(st, maxStringSize, stdin);
	if (result)
	{
		find = strchr(result, '\n');
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