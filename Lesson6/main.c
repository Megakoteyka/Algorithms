/*

Николай Макухин

*/

//1. Реализовать простейшую хеш - функцию.На вход функции подается строка, на выходе сумма кодов символов.

//2. Переписать программу, реализующую двоичное дерево поиска.
//	а) Добавить в него обход дерева различными способами;
//	б) Реализовать поиск в двоичном дереве поиска;

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node* root)
{
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");

			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");

			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

// Создание нового узла
Node* getTreeNode(int value, Node* parent)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// Вставка узла
void insert(Node** head, int value)
{
	Node* tmp = NULL;
	
	if (*head == NULL)
	{
		*head = getTreeNode(value, NULL);
		return;
	}

	tmp = *head;
	
	while (tmp)
	{
		if (value > tmp->data)
		{
			if (tmp->right)
				tmp = tmp->right;
			else
			{
				tmp->right = getTreeNode(value, tmp);
				return;
			}
		}
		else if (value < tmp->data)
		{
			if (tmp->left)
				tmp = tmp->left;
			else
			{
				tmp->left = getTreeNode(value, tmp);
				return;
			}
		}
		else
			exit(2); // дерево построено неправильно
	}
}

void preOrderTravers(Node* root)
{
	if (root)
	{
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}

// симметричный обход
void inOrderTravers(Node* root)
{
	if (root)
	{
		inOrderTravers(root->left);
		printf("%d ", root->data);
		inOrderTravers(root->right);
	}
}

// обратный обход
void postOrderTravers(Node* root)
{
	if (root)
	{
		postOrderTravers(root->left);
		postOrderTravers(root->right);
		printf("%d ", root->data);
	}
}

// поиск по дереву
Node* searchTree(Node* head, int value)
{
	if (head == NULL)
		return NULL;

	if (head->data == value)
		return head;

	if (head->data < value)
		return searchTree(head->right, value);
	return searchTree(head->left, value);
}

// простейший хэш для строки
unsigned char myStringHash(char* str)
{
	unsigned char hash = 0;
	while (*str)
		hash += *str++;
	return hash;
}

int main()
{
	Node* tree = NULL;
	FILE* file;
	int err = fopen_s(&file, "data.txt", "r");

	if (err)
	{
		puts("Can't open file!");
		_getch();
	}
	
	int count;
	fscanf_s(file, "%d", &count);          // Считываем количество записей
	int i;
	for (i = 0; i < count; i++)
	{
		int value;
		fscanf_s(file, "%d", &value);
		insert(&tree, value);
	}
	fclose(file);
	printTree(tree);
	
	printf("\nPreOrderTravers:  ");
	preOrderTravers(tree);

	printf("\nInOrderTravers:   ");
	inOrderTravers(tree);

	printf("\nPostOrderTravers: ");
	postOrderTravers(tree);

	printf("\nInput value to search: ");
	int sv;
	scanf_s("%d", &sv);

	Node* foundNode = searchTree(tree, sv);

	if (foundNode == NULL)
		printf("Value \"%d\" not found!", sv);
	else
		printf("Found node with value \"%d\"", foundNode->data);

	_getch();
	return 0;
}
