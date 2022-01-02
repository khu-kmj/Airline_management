#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "AirLine.h"
#define UP 72
#define DOWN 80
#define ENTER 13
#define ESC 27
#define SPACE 32
int main()
{
	hidecursor(); //커서를 숨긴다
	guest* gue = (guest*)malloc(sizeof(guest));
	Node* head = NULL;
	int c_max, d_max, count = 1;
	FILE* fp = fopen("plain.txt", "r");
	if (fp == NULL)
		printf("파일이 존재하지 않습니다!!\n");
	else
	{
		int i = 0;
		while (1) //파일의 내용을 gue 구조체에 저장
		{
			fscanf(fp, "%d\t%s\t%d\t%s", &gue[i].num, gue[i].name, &gue[i].score, gue[i].date);
			if (feof(fp))break;
			gue = (guest*)realloc(gue, sizeof(guest) * (++count));
			i++;
		}
		fclose(fp);
	}
	--count;
	int* arr = (int*)malloc(sizeof(int) * count);
	c_max = MAX_MAI(gue, count);//마일리지 최대 값
	d_max = MAX_DAY(arr, gue, count);//이용기간 최대 일
	Priority(gue, arr, c_max, d_max, count);//우선순위를 계산하여 gue구조체의 priority 실수형에 저장한다.
	for (int i = 0; i < count; i++) //이진 탐색 트리를 gue 구조체의 name으로 구성한다.
		head = Insert(head, gue[i]);
	char key;
	int x = 30, y = 11;
	while (1)
	{
		Menu(x, y); // 메뉴
		key = getch();
		switch (key)
		{
		case UP:
			y = y - 2;
			if (y < 11)
				y = 21;
			break;

		case DOWN:
			y = y + 2;
			if (y > 21)
				y = 11;
			break;
		}
		system("cls");
		if (key == ENTER && y == 11) // 1. 초기정보를 선택했을 때
		{
			Base(gue, count);
			break;
		}
		else if (key == ENTER && y == 13) // 2. 오름차순을 선택했을 때
		{
			ascending_order(gue, count);
			break;
		}
		else if (key == ENTER && y == 15) // 3. 정보추가를 선택했을 때
		{
			char name[20], date[40];
			int score, cou = 0;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("※ 이름이 6 글자 이상으로 넘어갈 시에 앞의 5글자만 추가 됩니다.\n");
			printf("※ 공백이 허용 되어지지 않습니다.\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("▶ 이름 : ");
			scanf("%s", name);
			printf("\n");
			printf("▶ 마일리지 : ");
			scanf("%d", &score);
			printf("\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("※ 날짜 입력 예시 : 1900-05-05 \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("▶ 이용 기간 : ");
			scanf("%s", date);
			if (strlen(name) > 10)  //이름이 한글로는 5글자, 영문으로 10글자를 초과했을 때 처리
			{
				char temp[11] = { 0, };
				for (int i = 0; i < 10; i++)
				{
					temp[i] = name[i];
				}
				strcpy(name, temp);
			}
			for (int i = 0; i < strlen(date); i++)
				if (date[i] == '-') //날짜 입력에서 '-'가 몇개인지 계산한다.
					cou++;
			while (strlen(date) != 10 || cou != 2)
			{
				int coun = 0;
				printf("\n※잘못 입력하셨습니다!\n");
				printf("▶ 이용 기간 : ");
				scanf("%s", date);
				for (int i = 0; i < strlen(date); i++)
					if (date[i] == '-')
						coun++;
				if (strlen(date) == 10 && coun == 2)break;
			}

			ADD(gue[count - 1].num, name, score, date);
			printf("\n정상적으로 추가되었습니다.");
			break;
		}
		else if (key == ENTER && y == 17) // 4. 정보삭제를 선택했을 때
		{
			char name[20];
			char key2;
			int capacity = 0;
			int x = 23, y = 4;
			guest* gue2 = NULL;
			printf("▶ 삭제하고자 하는 이름 : ");
			scanf("%s", name);
			gue2 = Search(name, head, gue2, capacity); //이름을 데이터로 찾은 모든 값을 gue2 구조체에 입력한다.
			while (1)
			{
				if (gue2 == NULL)
				{
					gotoxy(25, 5);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
					printf("※찾는 값이 존재 하지 않습니다.");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					print();

					break;
				}
				else
				{
					gotoxy(23, 2);
					printf("〓〓〓〓〓〓〓 SELECT 〓〓〓〓〓〓〓");
					for (int i = 0; i < capacity; i++) // 모든 이름 출력
					{
						gotoxy(25, 2 * (i + 2));
						printf("%d %s %d %s", gue2[i].num, gue2[i].name, gue2[i].score, gue2[i].date);
					}
				}
				gotoxy(23, 2 * (capacity + 2));
				printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
				gotoxy(x, y);
				printf("→");
				key2 = getch(); //key2를 이용해서 이름중 삭제할 데이터 선택
				switch (key2)
				{
				case UP:
					y = y - 2;
					if (y == 2)
						y = 2 * capacity + 2;
					break;
				case DOWN:
					y = y + 2;
					if (y == 2 * capacity + 4)
						y = 4;
					break;
				}
				system("cls");
				if (key2 == ENTER && y >= 4 && y % 2 == 0)
				{
					Delete(gue, gue2[(y / 2) - 2].num, count);
					printf("삭제가 완료되었습니다.");
					free(gue2);
					break;
				}
			}
			break;
		}
		else if (key == ENTER && y == 19)  //5. 마일리지 상품을 선택했을 때
		{
			char name[20];
			char key3;
			int x = 21, y = 4;
			guest* gue3 = NULL;
			int capacity = 0;
			printf("▶ 검색하고자 하는 이름 : ");
			scanf("%s", name);
			gue3 = Search(name, head, gue3, capacity); // 이름을 바탕으로 검색한 데이터 모두를 gue3 구조체에 입력한다.
			while (1)
			{
				if (gue3 == NULL)
				{
					gotoxy(25, 5);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
					printf("※찾는 값이 존재 하지 않습니다.");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					print();
					break;
				}
				else {
					gotoxy(23, 2);
					printf("〓〓〓〓〓〓〓 SELECT 〓〓〓〓〓〓〓");
					for (int i = 0; i < capacity; i++)
					{
						gotoxy(23, 2 * (i + 2));
						printf("%d %s %d %s", gue3[i].num, gue3[i].name, gue3[i].score, gue3[i].date);
					}
					gotoxy(23, 2 * (capacity + 2));
					printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
				}
				gotoxy(x, y);
				printf("→");
				key3 = getch(); // key3를 이용해서 마일리지 상품을 검색하고자하는 고객정보를 선택한다.
				switch (key3)
				{
				case UP:
					y = y - 2;
					if (y == 2)
						y = 2 * capacity + 2;
					break;
				case DOWN:
					y = y + 2;
					if (y == 2 * capacity + 4)
						y = 4;
					break;
				}
				system("cls");
				if (key3 == ENTER && y >= 4 && y % 2 == 0)
				{
					Mileage(gue, gue3[(y / 2) - 2]);
					free(gue3);
					break;
				}
			}
			break;
		}
		else if (key == ENTER && y == 21) // 6.프로그램을 종료한다. 
		{
			free(gue);
			free(arr);
			printf("프로그램을 종료하겠습니다.");
			return 0;
		}
	}
	key = getch();
	if (key == ESC) // 실행화면 안에서 ESC 키를 입력받으면 종료된다.
	{
		system("cls");
		free(gue);
		free(arr);
		printf("프로그램을 종료하겠습니다.");
	}
	else
	{
		if (key == SPACE && y <= 13)  // 실행화면 안에서 SPACE 키를 입력받으면 검색한다.
		{
			char key4;
			guest* gue4 = NULL;
			char name[20];
			int count = 0;
			printf("\n\n\n\n\n▶ 검색하고자 하는 이름 : ");
			scanf("%s", name);
			gue4 = Search(name, head, gue4, count); // 이름을 바탕으로 검색한 모든 데이터를 gue4구조체에 입력한다.
			if (count != 0) {
				printf("※검색 하신 이름으로 결과를 모두 출력 합니다.\n");
				gotoxy(18, 2);
				printf("〓〓〓〓〓〓〓< ALL CONSEQUENCE >〓〓〓〓〓〓〓");
				for (int i = 0; i < count; i++)
				{
					gotoxy(25, 2 * (i + 2));
					printf("%d %s %d %s", gue4[i].num, gue4[i].name, gue4[i].score, gue4[i].date);
				}
				gotoxy(18, 2 * (count + 2));
				printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
				print();
			}
			else
			{
				gotoxy(25, 5);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("※찾는 값이 존재 하지 않습니다.");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				print();
			}
			key4 = getch();
			if (key4 == ESC) // key4가 ESC이면 검색화면에서 종료한다. 
			{
				system("cls");
				free(gue4);
				free(gue);
				printf("프로그램을 종료하겠습니다.");
				return 0;
			}
		}
		free(gue);
		free(arr);
		system("cls");
		main();
	}
}