//����������� ��������� �������� ��������.
//��� ������� ��������� ���������� ����.
//����:
//1. ���������� �������
//2. �������� �������
//3. �������������� �������
//4. �������� �������
//5. �����
//������ ������ ������ ��������� ��������� ���������� :
//1. ���� �������� �������
//2. ��� �������
//3. ����� �������
//4. �������(�� 1 �� 10)

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

void openMenu(char* pass); //������� ��� �������� ����, � ������� ����������� ��������� ���������� ���������
void showAllRecipes(char* pass); //���������� ��� ����� � �����
void entereNameInPassToRecipe(char* pass, struct InfoAboutRecipe* infoAboutRecipe); //� ��� ��������� ���� ���������� �������. � ������, �������� ������ ����, � ������� ����������� �������� ������ (�����)
void addNewRecipe(char* pass); //������� �������� ������ �������
void openRecipe(char* pass); //������� ��������� ������
void reductRecipe(char* pass); //������� �������������� �������
void deleteRecipe(char* pass); //������� �������� �������
void cleanInput();


int main()
{
	setlocale(LC_ALL, "Rus");

	char* pass = malloc(RECIPE_PASS_SIZE);
	strcpy(pass, "E:\\Recipe Book\\");
	mkdir(pass);
	printf("����� ���������� � ����������� ����� ��������.\n");
	openMenu(pass);

	return 0;
}

void openMenu(char* pass)
{
	enum Menu menu;

	printf("\t\t����:\n1. �������� ��� �������.\n2. �������� ������.\n3. ���������� ������.\n"
		"4. �������������� �������.\n5. �������� �������.\n6. �����.\n�������� ���� �� ������� ��� �����������: ");
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
		printf("�������, ��� ������� ���. �� �������� � ���� �����!");
		return;
		break;
	default:
		system("cls");
		printf("������ ���������� �� ����������, ��������� ��������.\n");
		openMenu(pass);
		break;
	}
}

void entereNameInPassToRecipe(char* pass, struct InfoAboutRecipe* infoAboutRecipe)
{
	strcpy(pass, "E:\\Recipe Book\\");
	printf("������� �������� ������� �� ���������� �����: ");
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
		printf("������!");
		return;
	}
	printf("������� ��������� �������.\n");
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
	printf("������ � �������� %s ������.\n��������� ���������� � �������.\n", infoAboutRecipe->RecipeName);

	printf("������� ���� �������� � ������� ��.��.����: ");
	cleanInput();
	fgets(infoAboutRecipe->DateOfCreation, DATE_OF_CREATION_SIZE, stdin);
	int dateLength = strlen(infoAboutRecipe->DateOfCreation);
	while (dateLength > 11 || dateLength < 10)
	{
		printf("���� ������ �������.\n��������� ������: ");
		fgets(infoAboutRecipe->DateOfCreation, DATE_OF_CREATION_SIZE, stdin);
		dateLength = strlen(infoAboutRecipe->DateOfCreation);
	}
	printf("������� ���������� ������� (������������ ���-��: 5000 ������):\n");
	fgets(infoAboutRecipe->Recipe, RECIPE_SIZE, stdin);
	printf("������� ������� ������� �� 10-��������� ������� (1 - 10): ");
	scanf("%i", &infoAboutRecipe->Rate);
	while (infoAboutRecipe->Rate > 10 || infoAboutRecipe->Rate < 1)
	{
		printf("������� ����� �������.\n��������� ������: ");
		scanf("%i", &infoAboutRecipe->Rate);
	}

	fwrite(infoAboutRecipe, sizeof(struct InfoAboutRecipe), 1, newRecipe);

	free(infoAboutRecipe);
	fclose(newRecipe);

	printf("������ ������� ���������.\n");
	openMenu(pass);
}

void openRecipe(char* pass)
{
	struct InfoAboutRecipe* buff = malloc(sizeof(struct InfoAboutRecipe));
	entereNameInPassToRecipe(pass, buff);
	FILE* openRecipe = fopen(pass, "r+b");

	if (openRecipe == NULL)
	{
		printf("������. ������ �� ������.\n");
		free(buff);
		openMenu(pass);
	}
	else
	{
		system("cls");
		fread(buff, sizeof(struct InfoAboutRecipe), 1, openRecipe);
		printf("�������� �������: %s\n", buff->RecipeName);
		printf("���� ��������: %s", buff->DateOfCreation);
		printf("���������� �������: %s", buff->Recipe);
		printf("������: %i\n", buff->Rate);
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

	printf("�������� �������: %s\n", buff->RecipeName);
	printf("���� ��������: %s", buff->DateOfCreation);
	printf("������: %i\n", buff->Rate);
	printf("���������� �������: ");
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
		printf("������! ������ ������� �� ����������.\n");
		openMenu(pass);
	}
	else
	{
		printf("������ ������� �����.\n");
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
