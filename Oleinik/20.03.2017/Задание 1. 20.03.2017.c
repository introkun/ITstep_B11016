//Задание 1:
//Разработать программу для управления библиотекой книг(имя, автор, жанр, год) со
//следующими возможностями :
//• Добавление книг
//• Вывод списка книг
//• Сортировка по заданному критерию(имя, автор, жанр, год) с указанием
//направления сортировки

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 60

struct Library 
{
	char bookName[ARRAY_SIZE];
	char authorName[ARRAY_SIZE];
	char genre[ARRAY_SIZE];
	int yearOfWriting;
};

enum SortBy
{
	Name = 1,
	Author,
	Genre,
	Year
};

void entreNewBookToLibrary(struct Library* NewBook, int* bookQuantity);
void printBooksFromLibrary(struct Library* NewBook, int* bookQuantity);
void sortBooksInLibrary(struct Library* NewBook, int* bookQuantity);
void copyBook(struct Library* from, struct Library* to);

int main()
{
	setlocale(LC_ALL, "Rus");
	struct Library NewBook[ARRAY_SIZE];
	printf("Программа 'Библиотека'.\n");
	int bookQuantity;
	printf("Введите колличество добовляемых книг: ");
	scanf("%i", &bookQuantity);
	entreNewBookToLibrary(&NewBook, &bookQuantity);
	sortBooksInLibrary(&NewBook, &bookQuantity);
	printBooksFromLibrary(&NewBook, &bookQuantity);
	
}

void entreNewBookToLibrary(struct Library* NewBook, int* bookQuantity)
{
	
	for (int i = 0; i < *bookQuantity; i++)
	{
		printf("=== Книга %i ===\n", i + 1);

		char ch;
		do {
			ch = getchar();
		} while (ch != '\n' && ch != EOF);

		printf("Введите название книги: ");
		fgets(NewBook[i].bookName, ARRAY_SIZE, stdin);
		printf("Введите имя автора: ");
		fgets(NewBook[i].authorName, ARRAY_SIZE, stdin);
		printf("Введите жанр: ");
		fgets(NewBook[i].genre, ARRAY_SIZE, stdin);
		printf("Введите год написания книги: ");
		scanf("%i", &NewBook[i].yearOfWriting);
		
	}
}

void printBooksFromLibrary(struct Library* NewBook, int* bookQuantity)
{
	for (int j = 0; j < *bookQuantity; j++)
	{
		printf("=== Книга %i ===\n", j+1);
		printf("Название: %s", NewBook[j].bookName);
		printf("Имя автора: %s", NewBook[j].authorName);
		printf("Жанр: %s", NewBook[j].genre);
		printf("Год написания: %i\n", NewBook[j].yearOfWriting);
	}
}

void copyBook(struct Library* from, struct Library* to)
{
	strcpy(to->bookName, from->bookName);
	strcpy(to->authorName, from->authorName);
	strcpy(to->genre, from->genre);
	to->yearOfWriting = from->yearOfWriting;
}

void sortBooksInLibrary(struct Library* NewBook, int* bookQuantity)
{
	printf("Выберите по какому критерию будем сортировать книги:"
		"\n1. По названию книги.\n2. По имени автора.\n3. По жанру.\n4. По году издания.\nВыбор польователья: ");
	enum SortBy sortBy;
	scanf("%i", &sortBy);
	struct Library temp;
	for (int i = 0; i < *bookQuantity - 1; i++)
	{
		for (int j = 0; j < *bookQuantity - 1 - i; j++)
		{
			if (sortBy == Name && (NewBook[j].bookName, NewBook[j + 1].bookName) > 0 ||
				sortBy == Author && (NewBook[j].authorName, NewBook[j + 1].authorName) > 0 ||
				sortBy == Genre && (NewBook[j].genre, NewBook[j + 1].genre) > 0 ||
				sortBy == Year && (NewBook[j].yearOfWriting, NewBook[j + 1].yearOfWriting) > 0)
			{
				copyBook(&NewBook[j], &temp);
				copyBook(&NewBook[j + 1], &NewBook[j]);
				copyBook(&temp, &NewBook[j + 1]);
			}
		}
	}
}