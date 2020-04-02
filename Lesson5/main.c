/*

������� �������

*/

//1. ����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����.

//2. �������� � ��������� ����������� ����� �� ������ ������������ ������ �������� �� ��������� ������.
//���� ������ �� ����������, �� ��������� ��������������� ���������. ������������ ������� ��������, �����
//������ �� ����� ����������(����������� �������� ���������� ������).

//3. �������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ ����������.
//������� ���������� ��������� ��������� : (), ([])(), {}(), ([{}]), ������������ � )(, ())({ ), (, ]) }), ([(]) ��� ������[, (, { .
//��������: (2 + (2 * 2)) ���[2 / {5 * (4 + 7)}]

//4. * ������� �������, ���������� ����������� ������(�� ���� ������� � ������ ����� ������������ ������, �� ������ ������ ������).

//5. * *����������� �������� �������� �� ��������� ������ ��������������� ��������� � �����������.

//6. * ����������� �������.

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

// ���� �� ������ �������
typedef struct STACK_T
{
	int* buffer;
	int size;
	int count;
} Stack;

// ���� �������� ������
typedef struct NODE_T
{
	int value;
	struct NODE_T* next;
} Node;

// ���� �� ������ ������
typedef struct LINKED_STACK_T
{
	Node* head;
	int count;
} LinkedStack;

// ���� �� ������ �������: �������������
void stackInit(Stack* stack, int* buffer, int size)
{
	stack->buffer = buffer;
	stack->size = size;
	stack->count = 0;
}

// ���� �� ������ �������: ����������
void stackPush(Stack* s, int data)
{
	if (s->count == s->size)
		exit(1);

	s->buffer[s->count++] = data;	
}

// ���� �� ������ �������: ��������
int stackPop(Stack* s)
{
	if (s->count == 0)
		exit(1);

	s->count--;
	return s->buffer[s->count];
}

// ���� �� ������ ������: �������������
void linkedStackInit(LinkedStack* stack)
{
	stack->head = NULL;
	stack->count = 0;
}
// ���� �� ������ ������: ����������
void linkedStackPush(LinkedStack* stack, int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
		exit(ENOMEM);

	node->value = value;
	node->next = stack->head;

	stack->head = node;
	stack->count++;
}

// ���� �� ������ ������: ��������
int linkedStackPop(LinkedStack* stack)
{
	if (stack->count == 0)
		exit(-1);// �� ����� ���������� ��� ������, ������ ����� -1

	Node* tmp = stack->head;

	stack->head = stack->head->next;
	stack->count--;

	int value = tmp->value;
	free(tmp);
	return value;
}


void Ex1()
{
	printf("������� ���������� �����: ");
	int value;

	scanf_s("%d", &value);
	int value2 = value;

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

	
	
	printf("\n\n������ �� �� ����� � ������������� ����� �� ������ �������� ������.\n");
	
	LinkedStack ls;
	
	linkedStackInit(&ls);
	while (value2)
	{
		linkedStackPush(&ls, value2 & 1);
		value2 >>= 1;
	}
	
	printf("�������� �������������: ");

	while (ls.count)
		printf("%d", linkedStackPop(&ls));
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
		{ Ex1, "������� ����� �� ���������� ����� � �������� � ������� ����� (�� ������ ������� � �������� ������)" },
		{ Ex2, "������������ ��������� ������������������" },
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