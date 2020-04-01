/*

������� �������

*/

//1. ����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����.

//2. �������� ���������, ������� ����������, �������� �� ��������� ���������
//������������������ ����������.������� ���������� ��������� ��������� : (), ([])(), {}(),
//([{}]), ������������ � )(, ())({ ), (, ]) }), ([(]) ��� ������[, (, { .
//��������: (2 + (2 * 2)) ���[2 / {5 * (4 + 7)}].

//3. * ������� �������, ���������� ����������� ������(�� ���� ��������� � ������ �����
//������������ ������ ��� �������� ������� ������).

//4. * ����������� �������� �������� �� ��������� ������ ��������������� ��������� �
//�����������.

//5. ����������� ������� :
//	1. � �������������� �������.
//	2. * � �������������� ������������ ������.

//6. * **����������� ������������ �������.

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

#define MENU_SIZE 3

// ��������� ��� ����������� ����
typedef struct MENU_ITEM_T
{
	void (*func)();
	char* text;
} MenuItem;

typedef struct STACK_T
{
	int* buffer;
	int size;
	int count;
} Stack;

void stackInit(Stack* stack, int* buffer, int size)
{
	stack->buffer = buffer;
	stack->size = size;
	stack->count = 0;
}

void stackPush(Stack* s, int data)
{
	if (s->count == s->size)
		exit(1);

	s->buffer[s->count++] = data;	
}

int stackPop(Stack* s)
{
	if (s->count == 0)
		exit(1);

	s->count--;
	return s->buffer[s->count];
}

void Ex1()
{
	printf("������� ���������� �����: ");
	int value;

	scanf_s("%d", &value);

	Stack s;
	int buf[64];
	stackInit(&s, buf, 64);

	while (value)
	{
		stackPush(&s, value & 1);
		value >>= 1;
	}

	printf("�������� �������������: ");

	while (s.count)
		printf("%d", stackPop(&s));
}

int isOpenBrace(char c) { return c == '(' || c == '[' || c == '{'; }
int isCloseBrace(char c) { return c == ')' || c == ']' || c == '}'; }
int isBrace(char c) { return isOpenBrace(c) || isCloseBrace(c); }
int isCorrectBraces(char c1, char c2) { return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}'); }

void Ex2()
{
	printf("������� ������������������ �� ������: ");

	char str[64];
	scanf_s("%s", str, 63);

	Stack s;
	int buf[32];
	stackInit(&s, buf, 32);

	char* tmpStr = str;
	for (; *tmpStr; tmpStr++)
	{
		if (!isBrace(*tmpStr))
			continue;

		if (isOpenBrace(*tmpStr))
			stackPush(&s, *tmpStr);
		else if (isCloseBrace(*tmpStr))
			if (s.count == 0 || !isCorrectBraces(stackPop(&s), *tmpStr))
				break;

	}

	// ���� �� ����� �� ����� ������ - �� � ������ ���� ������
	if (*tmpStr)
		printf("������������������ ������ �������� ������\n");
	else
		printf("������������������ ������ ����������\n");
}

int main(int argc, char** argv)
{
	int selectedIndex;
	MenuItem currentItem;

	setlocale(LC_ALL, "Russian");

	MenuItem menu[MENU_SIZE] = {
		{ Ex1, "������� ����� �� ���������� ����� � �������� � ������� �����" },
		{ Ex2, "������������ ��������� ������������������" },
		//{ Ex3, "����� ��������� ����� �����" },
		{ 0, "�����" }
	};


	while (1)
	{
		system("cls");

		for (int i = 0; i < MENU_SIZE; i++)
			printf("%-4d%s\n", i + 1, menu[i].text);

		printf("\n��� �����: ");
		if (scanf_s("%d", &selectedIndex) != 1)
			continue;

		selectedIndex--;
		if (selectedIndex >= 0 && selectedIndex < MENU_SIZE)
		{
			currentItem = menu[selectedIndex];
			if (currentItem.func == 0)
				return 0;

			system("cls");
			printf("%s\n\n", currentItem.text);

			currentItem.func();

			printf("\n\n������� ����� ������� ��� �����������");
			_getch();
		}
	}

	return 0;
}