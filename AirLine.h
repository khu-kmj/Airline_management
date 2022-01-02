#include <stdio.h>
typedef struct guest
{
	int num;
	char name[20];
	int score;
	char date[40];
	float priority;
}guest;
typedef struct Node
{
	struct Node* L;
	struct Node* R;
	guest data;
}Node;
//=============menu===============
void gotoxy(int x, int y);
void Menu(int x, int y);
void hidecursor();
void print();
//===========priority=============
int MAX_MAI(guest* gue, int count);
int MAX_DAY(int* arr, guest* gue, int count);
void Priority(guest* gue, int* arr, int c_max, int d_max, int count);
//=============bst================
Node* Insert(Node* head, guest gue);
guest* Search(char* name, Node* head, guest* gue, int& count);
//=============main===============
void Base(guest* gue, int count);
void ADD(int count, char* name, int score, char* date);
void ascending_order(guest* gue, int count);
void Delete(guest* gue, int num, int count);
void Mileage(guest* gue, guest gue4);
//=================================
