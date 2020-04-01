/*

Николай Макухин

*/

//1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

//2. Написать программу, которая определяет, является ли введенная скобочная
//последовательность правильной.Примеры правильных скобочных выражений : (), ([])(), {}(),
//([{}]), неправильных — )(, ())({ ), (, ]) }), ([(]) для скобок[, (, { .
//Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}].

//3. * Создать функцию, копирующую односвязный список(то есть создающую в памяти копию
//односвязного списка без удаления первого списка).

//4. * Реализовать алгоритм перевода из инфиксной записи арифметического выражения в
//постфиксную.

//5. Реализовать очередь :
//	1. С использованием массива.
//	2. * С использованием односвязного списка.

//6. * **Реализовать двустороннюю очередь.

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

#define MENU_SIZE 3

// структура для организации меню
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
	printf("Введите десятичное число: ");
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

	printf("Двоичное представление: ");

	while (s.count)
		printf("%d", stackPop(&s));
}

int isOpenBrace(char c) { return c == '(' || c == '[' || c == '{'; }
int isCloseBrace(char c) { return c == ')' || c == ']' || c == '}'; }
int isBrace(char c) { return isOpenBrace(c) || isCloseBrace(c); }
int isCorrectBraces(char c1, char c2) { return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}'); }

void Ex2()
{
	printf("Введите последовательность из скобок: ");

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

	// если не дошли до конца строки - то в строке были ошибки
	if (*tmpStr)
		printf("Последовательность скобок СОДЕРЖИТ ОШИБКИ\n");
	else
		printf("Последовательность скобок ПРАВИЛЬНАЯ\n");
}

int main(int argc, char** argv)
{
	int selectedIndex;
	MenuItem currentItem;

	setlocale(LC_ALL, "Russian");

	MenuItem menu[MENU_SIZE] = {
		{ Ex1, "Перевод числа из десятичное формы в двоичную с помощью стека" },
		{ Ex2, "Правильность скобочной последовательности" },
		//{ Ex3, "Обход шахматной доски конем" },
		{ 0, "Выход" }
	};


	while (1)
	{
		system("cls");

		for (int i = 0; i < MENU_SIZE; i++)
			printf("%-4d%s\n", i + 1, menu[i].text);

		printf("\nВАШ ВЫБОР: ");
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

			printf("\n\nНажмите любую клавишу для продолжения");
			_getch();
		}
	}

	return 0;
}