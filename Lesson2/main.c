/*

Николай Макухин

*/

//1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя
//рекурсию.

//2. Реализовать функцию возведения числа a в степень b :
//a.Без рекурсии.
//b.Рекурсивно.
//c.* Рекурсивно, используя свойство чётности степени.

//3.** Исполнитель «Калькулятор» преобразует целое число, записанное на экране.У
//исполнителя две команды, каждой присвоен номер :
//1. Прибавь 1.
//2. Умножь на 2.
//Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза.Сколько
//существует программ, которые число 3 преобразуют в число 20 :
//	а.С использованием массива.
//	b.* С использованием рекурсии.

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

#define MENU_SIZE	4	// количество пунктов в меню

// структура для организации меню
typedef struct MENU_ITEM_T
{
	void (*func)();
	char* text;
} MenuItem;

void Ex1();
void Ex2();
void Ex3();


int main(int argc, char** argv)
{
	int selectedIndex;
	MenuItem currentItem;

	setlocale(LC_ALL, "Russian");

	MenuItem menu[MENU_SIZE] = {
		{ Ex1, "Перевод чисел из десятичной системы в двоичную" },
		{ Ex2, "Возведение в степень" },
		{ Ex3, "Обмен значениями переменных" },
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

			currentItem.func();

			printf("\n\nНажмите любую клавишу для продолжения");
			_getch();
		}
	};
}

//1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.

// НЕ СОВСЕМ ПОНЯЛ, ЧТО ИМЕННО ТРЕБОВАЛОСЬ СДЕЛАТЬ, ПОЭТОМУ ВОТ ТАК
int DecimalToBinary(int value)
{
	if (value == 0)
		return 0;
	return (value % 2) + DecimalToBinary(value / 2) * 10;
}

void Ex1()
{
	printf("== Ex1 ==");

	printf("Введите число: ");
	int value;

	if (scanf_s("%d", &value) != 1)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	int result = DecimalToBinary(value);

	printf("0b%d\n", result);
}


//2. Реализовать функцию возведения числа a в степень b :
//a.Без рекурсии.
int my_pow_a(int value, int power)
{
	if (power == 0)
		return 1;

	int result = 1;
	while (power-- > 0)
		result *= value;

	return result;
}

//2. Реализовать функцию возведения числа a в степень b :
//b.Рекурсивно.
int my_pow_b(int value, int power)
{
	if (power == 0)
		return 1;
	if (power == 1)
		return value;
	return value * my_pow_b(value, power - 1);
}

//2. Реализовать функцию возведения числа a в степень b :
//c.* Рекурсивно, используя свойство чётности степени.
int my_pow_c(int value, int power)
{
	if (power == 0)
		return 1;
	if (power == 1)
		return value;
	if (power == 2)
		return value * value;
	if ((power & 1) == 0)
		return my_pow_c(my_pow_c(value, 2), power / 2);
	return value * my_pow_c(value, power - 1);
}

void Ex2()
{
	printf("Введите число и степень через пробел: ");
	int value, power;

	if (scanf_s("%d %d", &value, &power) != 2)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	int result1 = my_pow_a(value, power);
	int result2 = my_pow_b(value, power);
	int result3 = my_pow_c(value, power);

	printf("Без рекурсии:                                    %d ^ %d == %d\n", value, power, result1);
	printf("Рекурсивно:                                      %d ^ %d == %d\n", value, power, result2);
	printf("Рекурсивно, используя свойство четности степени: %d ^ %d == %d\n", value, power, result3);
}


//3.** Исполнитель «Калькулятор» преобразует целое число, записанное на экране.У
//исполнителя две команды, каждой присвоен номер :
//1. Прибавь 1.
//2. Умножь на 2.
//Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза.Сколько
//существует программ, которые число 3 преобразуют в число 20 :
//	а.С использованием массива.
//	b.* С использованием рекурсии.
void Ex3()
{
	printf("== Ex3 ==");
}
