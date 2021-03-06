﻿/*

Макухин Николай

1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.

2. Найти максимальное из четырех чисел. Массивы не использовать.

3. Написать программу обмена значениями двух целочисленных переменных:
	a. с использованием третьей переменной;
	b. *без использования третьей переменной.

4. Написать программу нахождения корней заданного квадратного уравнения.

5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.

6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».

7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). Требуется определить, относятся ли к поля к одному цвету или нет.

8. Ввести a и b и вывести квадраты и кубы чисел от a до b.

9. Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.

10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.

11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.

12. Написать функцию нахождения максимального из трех чисел.

13. * Написать функцию, генерирующую случайное число от 1 до 100.
	с использованием стандартной функции rand()
	без использования стандартной функции rand()

14. * Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним
цифрам своего квадрата. Например, 25 \ :sup: `2` = 625. Напишите программу, которая вводит
натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.

*/



#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>


#define MENU_SIZE	15	// количество пунктов в меню

// макросы для задачек на поиск максимального числа
#define MAX(a, b)	((a) > (b) ? (a) : (b))
#define MAX3(a, b, c)	MAX(a, MAX(b, c))
#define MAX4(a, b, c, d)	MAX(MAX(a, b), MAX(c, d))

// четность числа (0 - четное, 1 - нечетное)
#define PARITY(x)	((x) & 1)




// структура для организации меню
typedef struct MENU_ITEM_T
{
	void (*func)();
	char* text;
} MenuItem;

// координаты точки
typedef struct POINT_T
{
	int x;
	int y;
} Point;


void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();
void Ex7();
void Ex8();
void Ex9();
void Ex10();
void Ex11();
void Ex12();
void Ex13();
void Ex14();


int main(int argc, char** argv)
{
	int selectedIndex;
	MenuItem currentItem;

	setlocale(LC_ALL, "Russian");

	MenuItem menu[MENU_SIZE] = {
		{ Ex1, "Индекс массы тела" },
		{ Ex2, "Максимум из четырех чисел" },
		{ Ex3, "Обмен значениями переменных" },
		{ Ex4, "Квадратное уравнение" },
		{ Ex5, "Времена года" },
		{ Ex6, "Возраст" },
		{ Ex7, "Шахматы (цвет полей)" },
		{ Ex8, "Квадраты и кубы" },
		{ Ex9, "Частное и остаток от деления" },
		{ Ex10, "Нечетный цифры в числе" },
		{ Ex11, "Среднее арифметическое 8" },
		{ Ex12, "Максимум из трех чисел" },
		{ Ex13, "Случайное число" },
		{ Ex14, "Автоморфные числа" },
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

		// 1..15 -> 0..14
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

//1. Ввести вес и рост человека.Рассчитать и вывести индекс массы тела по формуле I = m / (h * h); где m - масса тела в килограммах, h - рост в метрах.
void Ex1()
{
	double m, h, i;

	printf("Расчет индекса массы тела.\n");
	printf("Введите массу в килограммах и рост в метрах через пробел: ");
	if (scanf_s("%lf %lf", &m, &h) != 2)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	i = m / (h * h);

	printf("Индекс массы тела: %lf2\n", i);
}

//2. Найти максимальное из четырех чисел. Массивы не использовать.
void Ex2()
{
	int a, b, c, d;

	printf("Введите четыре числа через пробел: ");
	if(scanf_s("%d %d %d %d", &a, &b, &c, &d) != 4)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	printf("Максимальное число: %d\n", MAX4(a, b, c, d));
}

//3. Написать программу обмена значениями двух целочисленных переменных :
//a.с использованием третьей переменной;
//b.* без использования третьей переменной.
void Ex3()
{
	int a, b, tmp;
	
	printf("Обмен значениями двух переменных\n");
	printf("Введите 2 целых числа через пробел: ");

	if (scanf_s("%d %d", &a, &b) != 2)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	tmp = a;
	a = b;
	b = tmp;
	printf("С использованием третьей переменной: a = %d, b = %d\n", a, b);

	a ^= b ^= a ^= b;
	printf("Без использования третьей переменной: a = %d, b = %d\n", a, b);
}

//4. Написать программу нахождения корней заданного квадратного уравнения.
void Ex4()
{
	double a, b, c;
	double d, sqrtd, x1, x2;
	

	printf("Введите через пробел к-ты A, B, C квадратного уравнения A*x^2 + B*x + C: ");

	if(scanf_s("%lf %lf %lf", &a, &b, &c) != 3)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	d = b * b - 4 * a * c;

	if (d == 0)
	{
		x1 = -b / (2 * a);

		printf("x1 = x2 = %lf", x1);
	}
	else if (d > 0)
	{
		sqrtd = sqrt(d);

		x1 = (-b + sqrtd) / (2 * a);
		x2 = (-b - sqrtd) / (2 * a);

		printf("x1 = %lf, x2 = %lf", x1, x2);
	}
	else
		printf("Уравнение не имеет действительных корней");
}

//5. С клавиатуры вводится номер месяца.Требуется определить, к какому времени года он относится.
void Ex5()
{
	int month;
	printf("Введите номер месяца от 1 до 12: ");
	if(scanf_s("%d", &month) != 1 || month < 1 || month > 12)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	printf("Время года: ");

	if (month >= 3 && month <= 5)
		printf("весна");
	else if (month >= 6 && month <= 8)
		printf("лето");
	else if (month >= 9 && month <= 11)
		printf("осень");
	else
		printf("зима");
	printf("\n");
}

//6. Ввести возраст человека(от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
void Ex6()
{
	char * year0 = "лет", * year1 = "год", * year2 = "года";
	char* suffixes[] = { year0, year1, year2, year2, year2, year0, year0, year0, year0, year0 };

	int age;
	printf("Введите возраст от 1 до 150: ");
	if(scanf_s("%d", &age) != 1 || age < 1 || age > 150)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	printf("Возраст: %d %s\n", age, suffixes[age % 10]);
}

//7. С клавиатуры вводятся числовые координаты двух полей шахматной доски(x1, y1, x2, y2).Требуется определить, относятся ли к поля к одному цвету или нет.

int isValidCheckmatePoint(Point pt) { return pt.x >= 1 && pt.x <= 8 && pt.y >= 1 && pt.y <= 8; }

void Ex7()
{
	Point pt1, pt2;

	printf("Сперва вводится координата по горизонтали (1..8), а затем координата по вертикали (1..8)\n");

	printf("Введите координаты первой точки через пробел: ");
	if (scanf_s("%d %d", &pt1.x, &pt2.y) != 2 || !(isValidCheckmatePoint(pt1) && isValidCheckmatePoint(pt2)))
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	printf("Введите координаты второй точки через пробел: ");
	if (scanf_s("%d %d", &pt2.x, &pt2.y) != 2)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	// у черных клеток четность координат совпадает
	// у белых клеток четность координат не совпадает

	int isBlack1 = PARITY(pt1.x) == PARITY(pt1.y);
	int isBlack2 = PARITY(pt2.x) == PARITY(pt2.y);

	printf("Клетки имеют %s цвет\n", isBlack1 == isBlack2 ? "одинаковый" : "разный");
}

//8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
void Ex8()
{
	int a, b, i;

	printf("Введите a и b через пробел (a < b): ");
	if(scanf_s("%d %d", &a, &b) != 2 || a >= b)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	printf("%10s%10s%10s", "число", "квадрат", "куб");
	for (i = a; i <= b; i++)
		printf("%10d%10d%10d\n", i, i * i, i * i * i);
}

//9. Даны целые положительные числа N и K.Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.
void Ex9()
{
	int n, k, div = 0, rem;

	printf("Введите числа N и K через пробел: ");
	if(scanf_s("%d %d", &n, &k) != 2)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	rem = n;
	while (rem > k)
	{
		div++;
		rem -= k;
	}

	printf("divrem(%d, %d) = %d, %d\n", n, k, div, rem);
}

//10. Дано целое число N(> 0).С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры.Если имеются, то вывести True, если нет — вывести False.
void Ex10()
{
	printf("== Ex10 ==");
}

//11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.
void Ex11()
{
	printf("== Ex11 ==");
}

//12. Написать функцию нахождения максимального из трех чисел.
int max3(a, b, c) { return MAX3(a, b, c); }

void Ex12()
{
	int a, b, c;

	printf("Введите три числа через пробел: ");
	if (scanf_s("%d %d %d", &a, &b, &c) != 3)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	printf("Максимальное число: %d\n", max3(a, b, c));

}

//13.* Написать функцию, генерирующую случайное число от 1 до 100.
//с использованием стандартной функции rand()
//без использования стандартной функции rand()
void Ex13()
{
	printf("== Ex13 ==");
}

//14.* Автоморфные числа.Натуральное число называется автоморфным, если оно равно последним
//цифрам своего квадрата.Например, 25 \ :sup: `2` = 625. Напишите программу, которая вводит
//натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.
void Ex14()
{
	printf("== Ex14 ==");
}

