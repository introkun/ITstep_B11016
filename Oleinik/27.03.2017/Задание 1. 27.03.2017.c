//������� 1:
//�������� ���������, ������� ���� ������������ ������ 5 ������� ��������� � ������ ��
//� ������������ �������, � ����� ��������� �� �� �����������


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define QUANTITY 5

struct SecondNames
{
	char* secondNames;
};

void copyBook(struct SecondNames* from, struct SecondNames* to)
{
	strcpy(to->secondNames, from->secondNames);
	
}

int main()
{
	setlocale(LC_ALL, "Rus");
	struct SecondNames* arrayForSecondNames = malloc(5 * sizeof(struct SecondNames));
	for (int i = 0; i < QUANTITY; i++)
	{
		arrayForSecondNames[i].secondNames = malloc(100);
		fgets(arrayForSecondNames[i].secondNames, 100, stdin);

	}

	char temp[100];

	for (int i = 0; i < QUANTITY - 1; i++)
	{
		for (int j = 0; j < QUANTITY - 1 - i; j++)
		{
			if (strcmp(arrayForSecondNames[j].secondNames, arrayForSecondNames[j + 1].secondNames) == 1)
			{
				strcpy(arrayForSecondNames[j].secondNames, temp);
				strcpy(arrayForSecondNames[j + 1].secondNames, arrayForSecondNames[j].secondNames);
				strcpy(temp, arrayForSecondNames[j + 1].secondNames);
			}
		}
	}

	for (int i = 0; i < QUANTITY; i++)
	{
		printf("%s", arrayForSecondNames[i].secondNames);
	}
	
}
