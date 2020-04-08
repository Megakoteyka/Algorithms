/*

Николай Макухин

*/

//1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.

//2. Написать рекурсивную функцию обхода графа в глубину.

//3. Написать функцию обхода графа в ширину.


#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int** loadSquareMatrix(char* fileName, int* n)
{
	FILE* file;
	int i,j;
	
	fopen_s(&file, fileName, "r");

	fscanf_s(file, "%d", n);

	int** m = (int**)malloc(*n * sizeof(int*));
	
	for (i = 0; i < *n; i++)
	{
		m[i] = (int*)malloc(*n * sizeof(int));
		for (j = 0; j < *n; j++)
			fscanf_s(file, "%d", &m[i][j]);
	}

	return m;
}

void deleteSquareMatrix(int** m, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(m[i]);
	free(m);
}

void printSquareMatrix(int** m, int n)
{
	int i, j;

	printf("  ");
	for (i = 0; i < n; i++)
		printf("%2c", 'A' + i);

	for (i = 0; i < n; i++)
	{
		printf("\n%-2c", 'A' + i);
		for (j = 0; j < n; j++)
			printf("%2d", m[i][j]);
		//printf("\n");
	}
}

// обход в глубину
void depthSearch(int** m, int* visited, int n, int curr)
{
	int i;
	
	printf("%c ", 'A' + curr);

	visited[curr] = 1;
	
	for (i = 0; i < n; i++)
		if (m[i][curr] && !visited[i])
			depthSearch(m, visited, n, i);
}

void widthSearch(int** m, int* visited, int n, int curr)
{
	int i;

	printf("%c ", 'A' + curr);
	visited[curr] = 1;
	
	for (i = 0; i < n; i++)
		if (m[i][curr] && !visited[i])
		{
			visited[i] = 1;
			printf("%c ", 'A' + i);
		}

	for (i = 0; i < n; i++)
		if (!visited[i])
			widthSearch(m, visited, n, i);
}

int main(int argc, char** argv)
{
	int n;

	setlocale(LC_ALL, "Russian");

	int** m = loadSquareMatrix("data.txt", &n);

	int* visited = (int*)malloc(n * sizeof(int));
	memset(visited, 0, n * sizeof(int));


	printf("Матрица смежности графа:\n");
	printSquareMatrix(m, n);

	printf("\n\nОбход графа в глубину: ");
	depthSearch(m, visited, n, 0);

	printf("\n\nОбход графа в ширину: ");
	memset(visited, 0, n * sizeof(int));
	widthSearch(m, visited, n, 0);

	deleteSquareMatrix(m, n);
	free(visited);

	_getch();
	return 0;
}