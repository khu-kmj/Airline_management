#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "AirLine.h"
Node* Insert(Node* head, guest gue) //노드 삽입
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