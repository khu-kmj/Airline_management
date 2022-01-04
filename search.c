#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "AirLine.h"
Node* Insert(Node* head, guest gue)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->L = newnode->R = NULL;
	newnode->data = gue;
	Node* temp = head;
	Node* parent = NULL;
	while (temp != NULL)
	{
		parent = temp;
		if (strcmp(temp->data.name, gue.name) >= 0)
			temp = temp->L;
		else
			temp = temp->R;
	}
	if (parent != NULL)
		if (strcmp(parent->data.name, gue.name) >= 0)
			parent->L = newnode;
		else
			parent->R = newnode;
	else
		head = newnode;
	return head;
}

guest* Search(char* name, Node* head, guest* gue, int& count) 
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp->data.name, name) == 0)
		{
			if (count == 0)
				gue = (guest*)malloc(sizeof(guest));
			else
				gue = (guest*)realloc(gue, sizeof(guest) * (count + 1));
			gue[count] = temp->data;
			count++;
			temp = temp->L;
		}
		else if (strcmp(temp->data.name, name) > 0)
			temp = temp->L;
		else
			temp = temp->R;
	}
	system("cls");
	gotoxy(29, 7);
	printf("┌─────────────────┐");
	for (int i = 0; i < 4; i++)
	{
		gotoxy(29, 8 + i);
		printf("│");
		gotoxy(47, 8 + i);
		printf("│");
	}
	gotoxy(29, 11);
	printf("└─────────────────┘");
	gotoxy(33, 9);
	printf("검색중입니다.\n");
	Sleep(1000);
	system("cls");
	return gue;
}