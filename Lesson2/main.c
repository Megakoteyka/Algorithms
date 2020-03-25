/*

������� �������

*/

//1. ����������� ������� �������� ����� �� ���������� ������� � ��������, ���������
//��������.

//2. ����������� ������� ���������� ����� a � ������� b :
//a.��� ��������.
//b.����������.
//c.* ����������, ��������� �������� �������� �������.

//3.** ����������� ������������ ����������� ����� �����, ���������� �� ������.�
//����������� ��� �������, ������ �������� ����� :
//1. ������� 1.
//2. ������ �� 2.
//������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� � 2 ����.�������
//���������� ��������, ������� ����� 3 ����������� � ����� 20 :
//	�.� �������������� �������.
//	b.* � �������������� ��������.

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

#define MENU_SIZE	4	// ���������� ������� � ����

// ��������� ��� ����������� ����
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
		{ Ex1, "������� ����� �� ���������� ������� � ��������" },
		{ Ex2, "���������� � �������" },
		{ Ex3, "����� ���������� ����������" },
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

			currentItem.func();

			printf("\n\n������� ����� ������� ��� �����������");
			_getch();
		}
	};
}

//1. ����������� ������� �������� ����� �� ���������� ������� � ��������, ��������� ��������.

// �� ������ �����, ��� ������ ����������� �������, ������� ��� ���
int DecimalToBinary(int value)
{
	if (value == 0)
		return 0;
	return (value % 2) + DecimalToBinary(value / 2) * 10;
}

void Ex1()
{
	printf("== Ex1 ==");

	printf("������� �����: ");
	int value;

	if (scanf_s("%d", &value) != 1)
	{
		printf("������ �����\n");
		return;
	}

	int result = DecimalToBinary(value);

	printf("0b%d\n", result);
}


//2. ����������� ������� ���������� ����� a � ������� b :
//a.��� ��������.
int my_pow_a(int value, int power)
{
	if (power == 0)
		return 1;

	int result = 1;
	while (power-- > 0)
		result *= value;

	return result;
}

//2. ����������� ������� ���������� ����� a � ������� b :
//b.����������.
int my_pow_b(int value, int power)
{
	if (power == 0)
		return 1;
	if (power == 1)
		return value;
	return value * my_pow_b(value, power - 1);
}

//2. ����������� ������� ���������� ����� a � ������� b :
//c.* ����������, ��������� �������� �������� �������.
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
	printf("������� ����� � ������� ����� ������: ");
	int value, power;

	if (scanf_s("%d %d", &value, &power) != 2)
	{
		printf("������ �����\n");
		return;
	}

	int result1 = my_pow_a(value, power);
	int result2 = my_pow_b(value, power);
	int result3 = my_pow_c(value, power);

	printf("��� ��������:                                    %d ^ %d == %d\n", value, power, result1);
	printf("����������:                                      %d ^ %d == %d\n", value, power, result2);
	printf("����������, ��������� �������� �������� �������: %d ^ %d == %d\n", value, power, result3);
}


//3.** ����������� ������������ ����������� ����� �����, ���������� �� ������.�
//����������� ��� �������, ������ �������� ����� :
//1. ������� 1.
//2. ������ �� 2.
//������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� � 2 ����.�������
//���������� ��������, ������� ����� 3 ����������� � ����� 20 :
//	�.� �������������� �������.
//	b.* � �������������� ��������.
void Ex3()
{
	printf("== Ex3 ==");
}
