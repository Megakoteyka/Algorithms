/*

Николай Макухин

*/

//1. * Количество маршрутов с препятствиями.
//Реализовать чтение массива с препятствием и нахождение количество маршрутов.
//Например, карта:
//3 3
//1 1 1
//0 1 0
//0 1 0

//2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.

//3. * **Требуется обойти конем шахматную доску размером NxM, пройдя через все поля доски по одному разу.
//Здесь алгоритм решения такой же, как в задаче о 8 ферзях.Разница только в проверке положения коня.


#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int** createMatrix(int columns, int rows)
{
	char** m = (int**)malloc(columns * sizeof(int*));
	for (int i = 0; i < columns; i++)
		m[i] = (int*)malloc(rows * sizeof(int));
	return m;
}

void deleteMatrix(int** m, int columns, int rows)
{
	for (int i = 0; i < columns; i++)
		free(m[i]);
	free(m);
}

void printMatrix(int** m, int columns, int rows)
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
			printf("%2d", m[i][j]);
		printf("\n");
	}
}

int lcs_len(char* s1, char* s2)
{
	int columns = strlen(s1) + 1;
	int rows = strlen(s2) + 1;

	int** m = createMatrix(columns, rows);

	for (int i = 0; i < columns; i++)
		m[i][0] = 0;
	for (int j = 0; j < rows; j++)
		m[0][j] = 0;

	for (int i = 1; i < columns; i++)
		for (int j = 1; j < rows; j++)
			m[i][j] = s1[i] == s2[j] ? m[i - 1][j - 1] + 1 : max(m[i - 1][j], m[i][j - 1]);

	int len = m[columns - 1][rows - 1];

	deleteMatrix(m, columns, rows);

	return len;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	// 2
	char* seq1 = "geekbrains";
	char* seq2 = "geekminds";

	printf("sequence 1: %s\n", seq1);
	printf("sequence 2: %s\n", seq2);
	printf("lcs_len = %d\n", lcs_len(seq1, seq2));


	return 0;
}