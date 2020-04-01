/*

Николай Макухин

*/

//1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения
//оптимизированной и не оптимизированной программы. Написать функции сортировки, которые
//возвращают количество операций.

//2. *Реализовать шейкерную сортировку.

//3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный
//массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.

//4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической
//сложностью алгоритма.

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>

int count_cmp = 0;
int count_swp = 0;

void init_array(int* data, int len)
{
	while (len--)
		*data++ = 1 + rand() % 100;
}

void print_array(int* data, int len)
{
	printf("[ ");
	while (len--)
		printf("%d ", *data++);
	printf("]\n");
}

void reset_counters() { count_cmp = count_swp = 0; }

void print_counters() { printf("Количество сравнений/перестановок: %d/%d\n", count_cmp, count_swp); }

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int* data, int len)
{
	int i, j;

	reset_counters();

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - 1; j++)
		{
			count_cmp++;
			if (data[j] > data[j + 1])
			{
				count_swp++;
				swap(&data[j], &data[j + 1]);
			}
		}
	}
}

void bubble_sort_ex(int* data, int len)
{
	int i, j;

	reset_counters();

	// с последним элементом ничего делать не нужно, поэтому len - 1
	for (i = 0; i < len - 1; i++)
	{
		// не нужно идти до конца массива - только до первого неотсортированного элемента, поэтому len - i - 1
		for (j = 0; j < len - i - 1; j++)
		{
			count_cmp++;
			if (data[j] > data[j + 1])
			{
				count_swp++;
				swap(&data[j], &data[j + 1]);
			}
		}
	}
}

int binary_search(int* data, int len, int value)
{
	int mid, min = 0, max = len - 1;

	while (min <= max)
	{
		mid = (min + max) / 2;

		if (data[mid] == value)
			return mid;

		if (data[mid] < value)
			min = mid + 1;
		else
			max = mid - 1;
	}

	return -1;
}

void shaker_sort(int* data, int len)
{
	int i, min, max;

	reset_counters();

	for (min = 0, max = len - 1; min <= max;)
	{
		for (i = min; i < max; i++)
		{
			count_cmp++;
			if (data[i] > data[i + 1])
			{
				count_swp++;
				swap(&data[i], &data[i + 1]);
			}
		}
		max--;

		for(i = max; i > min; i--)
		{			
			count_cmp++;
			if (data[i] < data[i - 1])
			{
				count_swp++;
				swap(&data[i], &data[i - 1]);
			}
		}
		min++;
	}
}

int main(int argc, char** argv)
{
	int len = 0;
	int* data;
	int* sorted_data;
	int search_value, search_index;
	time_t t = 0;

	setlocale(LC_ALL, "Russian");

	time(&t);

	srand((unsigned int)t);
	
	printf("Введите длину массива: ");
	if (scanf_s("%d", &len) != 1)
	{
		printf("ОШИБКА ВВОДА\n");
		return;
	}

	data = (int*)malloc(len * sizeof(int));
	sorted_data = (int*)malloc(len * sizeof(int));

	init_array(data, len);
	printf("Исходный массив: ");
	print_array(data, len);

	printf("\nПузырек 1: ");
	memcpy(sorted_data, data, len * sizeof(int));
	bubble_sort(sorted_data, len);
	print_array(sorted_data, len);
	print_counters();

	printf("\nПузырек 2: ");
	memcpy(sorted_data, data, len * sizeof(int));
	bubble_sort_ex(sorted_data, len);
	print_array(sorted_data, len);
	print_counters();

	printf("\nШейкер:    ");
	memcpy(sorted_data, data, len * sizeof(int));
	shaker_sort(sorted_data, len);
	print_array(sorted_data, len);
	print_counters();

	printf("\nВведите значение для поиска: ");
	scanf_s("%d", &search_value);

	search_index = binary_search(sorted_data, len, search_value);
	if (search_index < 0)
		printf("Элемент %d не найден\n", search_value);
	else
		printf("Позиция элемента: %d\n", search_index);

	free(data);
	free(sorted_data);
}



