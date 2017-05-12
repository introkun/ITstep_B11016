//Разработать программу хранения рецептов.
//При запуске программа показывает меню.
//Меню:
//1. Добавление рецепта
//2. Просмотр рецепта
//3. Редактирование рецепта
//4. Удаление рецепта
//5. Выход
//Каждый рецепт должен содержать следующую информацию :
//1. Дату создания рецепта
//2. Имя рецепта
//3. Текст рецепта
//4. Рейтинг(от 1 до 10)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <direct.h>
#include <Windows.h>

#define RECIPE_NAME_SIZE 100
#define RECIPE_PASS_SIZE 117
#define RECIPE_SIZE 5000
#define DATE_OF_CREATION_SIZE 15

struct InfoAboutRecipe
{
	char DateOfCreation[DATE_OF_CREATION_SIZE];
	char RecipeName[RECIPE_NAME_SIZE];
	char Recipe[RECIPE_SIZE];
	int Rate;
};

enum Menu
{
	ShowAllRecipes = 1,
	AddRecipe,
	OpenRecipe,
	CorrectingRecipe,
	DeletingRecipe,
	Exit,
	Continue = 1
};

void openMenu(char* pass); //функция для открытия меню, в котором вызываеются отдельный функционал программы
void showAllRecipes(char* pass); //показывает все файлы в папке
void entereNameInPassToRecipe(char* pass, struct InfoAboutRecipe* infoAboutRecipe); //в ней создается путь сохранения рецепта. А имеено, вводится основа пути, к которое добавляется название рецпта (файла)
void addNewRecipe(char* pass); //функция создания нового рецепта
void openRecipe(char* pass); //функция просмотра рецепт
void reductRecipe(char* pass); //функция редактирования рецепта
void deleteRecipe(char* pass); //функция удаления рецепта
void cleanInput();


int main()
{
	setlocale(LC_ALL, "Rus");

	char* pass = malloc(RECIPE_PASS_SIZE);
	strcpy(pass, "E:\\Recipe Book\\");
	mkdir(pass);
	printf("Добро пожаловать в электронную книгу рецептов.\n");
	openMenu(pass);

	return 0;
}

void openMenu(char* pass)
{
	enum Menu menu;

	printf("\t\tМеню:\n1. Показать все рецепты.\n2. Добавить рецепт.\n3. Посмотреть рецепт.\n"
		"4. Редактирование рецепта.\n5. Удаление рецепта.\n6. Выход.\nВыберите один из пунктов для продолжения: ");
	scanf("%i", &menu);

	switch (menu)
	{
	case ShowAllRecipes:
		system("cls");
		showAllRecipes(pass);
		break;
	case AddRecipe:
		system("cls");
		addNewRecipe(pass);
		break;
	case OpenRecipe:
		system("cls");
		openRecipe(pass);
		break;
	case CorrectingRecipe:
		system("cls");
		reductRecipe(pass);
		break;
	case DeletingRecipe:
		system("cls");
		deleteRecipe(pass);
		break;
	case Exit:
		printf("Спасибо, что выбрали нас. Да прибудет с вами кухня!");
		return;
		break;
	default:
		system("cls");
		printf("Данная переменная не распознана, повторите операцию.\n");
		openMenu(pass);
		break;
	}
}

void entereNameInPassToRecipe(char* pass, struct InfoAboutRecipe* infoAboutRecipe)
{
	strcpy(pass, "E:\\Recipe Book\\");
	printf("Введите название рецепта на английском языке: ");
	cleanInput();
	scanf("%s", &infoAboutRecipe->RecipeName);
	strcat(pass, infoAboutRecipe->RecipeName, RECIPE_NAME_SIZE);
	strcat(pass, ".recipe", 8);
}

void showAllRecipes(char* pass)
{
	WIN32_FIND_DATAA found;
	struct InfoAboutRecipe* buff = malloc(sizeof(struct InfoAboutRecipe));
	HANDLE findResult = FindFirstFileA("E:\\Recipe Book\\*.recipe", &found);
	if (FindFirstFileA == INVALID_HANDLE_VALUE)
	{
		printf("Ошибка!");
		return;
	}
	printf("Имеются следующие рецепты.\n");
	do
	{
		printf("%s\n", found.cFileName);
	} while (FindNextFileA(findResult, &found));
	openMenu(pass);
}

void addNewRecipe(char* pass)
{
	struct InfoAboutRecipe* infoAboutRecipe = malloc(sizeof(struct InfoAboutRecipe));

	entereNameInPassToRecipe(pass, infoAboutRecipe);

	FILE* newRecipe = fopen(pass, "wb");
	printf("Рецепт с название %s создан.\nЗаполните информацию о рецепте.\n", infoAboutRecipe->RecipeName);

	printf("Введите дату создания в формате ДД.ММ.ГГГГ: ");
	cleanInput();
	fgets(infoAboutRecipe->DateOfCreation, DATE_OF_CREATION_SIZE, stdin);
	int dateLength = strlen(infoAboutRecipe->DateOfCreation);
	while (dateLength > 11 || dateLength < 10)
	{
		printf("Дата введёна неверно.\nПовторите запись: ");
		fgets(infoAboutRecipe->DateOfCreation, DATE_OF_CREATION_SIZE, stdin);
		dateLength = strlen(infoAboutRecipe->DateOfCreation);
	}
	printf("Введите содержание рецепта (максимальное кол-во: 5000 знаков):\n");
	fgets(infoAboutRecipe->Recipe, RECIPE_SIZE, stdin);
	printf("Введите рейтинг рецепта по 10-тибальной системе (1 - 10): ");
	scanf("%i", &infoAboutRecipe->Rate);
	while (infoAboutRecipe->Rate > 10 || infoAboutRecipe->Rate < 1)
	{
		printf("Рейтинг введён неверно.\nПовторите запись: ");
		scanf("%i", &infoAboutRecipe->Rate);
	}

	fwrite(infoAboutRecipe, sizeof(struct InfoAboutRecipe), 1, newRecipe);

	free(infoAboutRecipe);
	fclose(newRecipe);

	printf("Запись рецепта завершена.\n");
	openMenu(pass);
}

void openRecipe(char* pass)
{
	struct InfoAboutRecipe* buff = malloc(sizeof(struct InfoAboutRecipe));
	entereNameInPassToRecipe(pass, buff);
	FILE* openRecipe = fopen(pass, "r+b");

	if (openRecipe == NULL)
	{
		printf("Ошибка. Рецепт не найден.\n");
		free(buff);
		openMenu(pass);
	}
	else
	{
		system("cls");
		fread(buff, sizeof(struct InfoAboutRecipe), 1, openRecipe);
		printf("Название рецепта: %s\n", buff->RecipeName);
		printf("Дата создания: %s", buff->DateOfCreation);
		printf("Содержание рецепта: %s", buff->Recipe);
		printf("Оценка: %i\n", buff->Rate);
		fclose(openRecipe);
		free(buff);
		openMenu(pass);

	}
}

void reductRecipe(char* pass)
{
	struct InfoAboutRecipe* buff = malloc(sizeof(struct InfoAboutRecipe));
	entereNameInPassToRecipe(pass, buff);

	FILE* openForReductRecipe = fopen(pass, "r+b");
	fread(buff, sizeof(struct InfoAboutRecipe), 1, openForReductRecipe);
	fclose(openForReductRecipe);

	printf("Название рецепта: %s\n", buff->RecipeName);
	printf("Дата создания: %s", buff->DateOfCreation);
	printf("Оценка: %i\n", buff->Rate);
	printf("Содержание рецепта: ");
	cleanInput();
	fgets(buff->Recipe, RECIPE_SIZE, stdin);

	FILE* reductRecipe = fopen(pass, "w+b");
	fwrite(buff, sizeof(struct InfoAboutRecipe), 1, reductRecipe);
	fclose(reductRecipe);
	free(buff);

	openMenu(pass);
}

void deleteRecipe(char* pass)
{
	struct InfoAboutRecipe* buff = malloc(sizeof(struct InfoAboutRecipe));

	entereNameInPassToRecipe(pass, buff);

	if (remove(pass) == -1)
	{
		printf("Ошибка! Такого рецепта не существует.\n");
		openMenu(pass);
	}
	else
	{
		printf("Рецепт успешно удалён.\n");
		openMenu(pass);
	}
}

void cleanInput()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}
