#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "AirLine.h"

// 좌표 설정 함수
void gotoxy(int x, int y) 
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 커서 숨기기 함수
void hidecursor() 
{
	CONSOLE_CURSOR_INFO c = { 0 };
	c.dwSize = 1;
	c.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}

// key 입력에 대한 설명
void print() 
{
	gotoxy(26, 23);
	printf("o Continue : press ANY key");
	gotoxy(26, 24);
	printf("o Exit : press ESC key");
}

 // 메뉴를 출력
void Menu(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	gotoxy(22, 5);
	printf("□□□□□□□□□□□□□□□□□");
	for (int i = 4; i >= 1; i--)
	{
		gotoxy(39 - i, i);
		printf("□");
	}
	gotoxy(39, 1);
	printf("□□□");
	for (int i = 4; i >= 1; i--)
	{
		gotoxy(43 - i, i);
		printf("□");
	}
	gotoxy(19, 6);
	printf("□□");
	gotoxy(22, 7);
	printf("□□□□□□□□□□□□□□□□□□");
	gotoxy(57, 6);
	printf("□");
	gotoxy(58, 5);
	printf("□");
	gotoxy(55, 4);
	printf("□ □");
	gotoxy(56, 3);
	printf("□□");
	gotoxy(57, 2);
	printf("□");
	gotoxy(27, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("King Wang Jang Mj AirLine");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(28, 9);
	printf("┌──────  MENU ──────┐");
	for (int i = 0; i < 13; i++)
	{
		gotoxy(28, 10 + i);
		printf("│\n");
		gotoxy(48, 10 + i);
		printf("│\n");
	}
	gotoxy(28, 23);
	printf("└───────────────────┘");
	gotoxy(29, 25);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("press enter to search");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(x, y);
	printf("→");
	gotoxy(32, 11);
	printf("1. 초기정보");
	gotoxy(32, 13);
	printf("2. 오름차순");
	gotoxy(32, 15);
	printf("3. 정보추가");
	gotoxy(32, 17);
	printf("4. 정보삭제");
	gotoxy(32, 19);
	printf("5. 마일리지 상품");
	gotoxy(32, 21);
	printf("6. 종료");
}