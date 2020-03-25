/*

������� �������

*/

//1. ����������� �������������� ����������� ����������. �������� ���������� �������� ���������
//���������������� � �� ���������������� ���������. �������� ������� ����������, �������
//���������� ���������� ��������.

//2. *����������� ��������� ����������.

//3. ����������� �������� �������� ������ � ���� �������, ������� ���������� ���������������
//������. ������� ���������� ������ ���������� �������� ��� -1, ���� ������� �� ������.

//4. *���������� ���������� �������� ��� ������ �� ���������� � �������� ��� � ���������������
//���������� ���������.

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

void print_counters() { printf("���������� ���������/������������: %d/%d\n", count_cmp, count_swp); }

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

	// � ��������� ��������� ������ ������ �� �����, ������� len - 1
	for (i = 0; i < len - 1; i++)
	{
		// �� ����� ���� �� ����� ������� - ������ �� ������� ������������������ ��������, ������� len - i - 1
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
	
	printf("������� ����� �������: ");
	if (scanf_s("%d", &len) != 1)
	{
		printf("������ �����\n");
		return;
	}

	data = (int*)malloc(len * sizeof(int));
	sorted_data = (int*)malloc(len * sizeof(int));

	init_array(data, len);
	printf("�������� ������: ");
	print_array(data, len);

	printf("\n������� 1: ");
	memcpy(sorted_data, data, len * sizeof(int));
	bubble_sort(sorted_data, len);
	print_array(sorted_data, len);
	print_counters();

	printf("\n������� 2: ");
	memcpy(sorted_data, data, len * sizeof(int));
	bubble_sort_ex(sorted_data, len);
	print_array(sorted_data, len);
	print_counters();

	printf("\n������:    ");
	memcpy(sorted_data, data, len * sizeof(int));
	shaker_sort(sorted_data, len);
	print_array(sorted_data, len);
	print_counters();

	printf("\n������� �������� ��� ������: ");
	scanf_s("%d", &search_value);

	search_index = binary_search(sorted_data, len, search_value);
	if (search_index < 0)
		printf("������� %d �� ������\n", search_value);
	else
		printf("������� ��������: %d\n", search_index);

	free(data);
	free(sorted_data);
}



