#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AirLine.h"
void Base(guest* gue, int count) // ����Ǿ��ִ� ������ ����Ѵ�.
{
	gotoxy(17, 0);
	printf("������������������������������������������������������������������������������");
	gotoxy(16, 1);
	printf("   ����    �̸�   ���ϸ���   ���Գ⵵");
	for (int i = 0; i < count; i++)
	{
		gotoxy(17, i + 1);
		printf("��");
		gotoxy(55, i + 1);
		printf("��");
		if (i == 0)
		{
			gotoxy(17, 2);
			printf("����������������������������������������������������������������������������");
		}
		gotoxy(20, i + 3);
		if (gue[i].num > 99)
		{
			if (strlen(gue[i].name) == 10)
				printf("%d %s %d", gue[i].num, gue[i].name, gue[i].score);
			else if (strlen(gue[i].name) == 8)
				printf("%d  %s  %d", gue[i].num, gue[i].name, gue[i].score);
			else if (strlen(gue[i].name) == 4)
				printf("%d    %s    %d", gue[i].num, gue[i].name, gue[i].score);
			else
				printf("%d   %s   %d", gue[i].num, gue[i].name, gue[i].score);
		}
		else if (gue[i].num > 9)
		{
			if (strlen(gue[i].name) == 8)
				printf("%d   %s  %d", gue[i].num, gue[i].name, gue[i].score);
			else if (strlen(gue[i].name) == 4)
				printf("%d     %s    %d", gue[i].num, gue[i].name, gue[i].score);
			else
				printf("%d    %s   %d", gue[i].num, gue[i].name, gue[i].score);
		}
		else
		{
			if (strlen(gue[i].name) == 8)
				printf("%d    %s   %d", gue[i].num, gue[i].name, gue[i].score);
			else if (strlen(gue[i].name) == 4)
				printf("%d      %s    %d", gue[i].num, gue[i].name, gue[i].score);
			else
				printf("%d     %s   %d", gue[i].num, gue[i].name, gue[i].score);
		}
		gotoxy(44, i + 3);
		printf("%s", gue[i].date);
	}
	for (int i = count; i < count + 2; i++)
	{
		gotoxy(17, i + 1);
		printf("��");
		gotoxy(55, i + 1);
		printf("��");
	}
	gotoxy(17, count + 3);
	printf("������������������������������������������������������������������������������");
	gotoxy(58, count - 1);
	printf("������������������������������������������");
	for (int i = 3; i > 0; i--)
	{
		gotoxy(58, count + 3 - i);
		printf("��\n");
		gotoxy(78, count + 3 - i);
		printf("��\n");
	}
	gotoxy(58, count + 3);
	printf("������������������������������������������");
	gotoxy(60, count);
	printf("o ���� : ESC");
	gotoxy(60, count + 1);
	printf("o �˻� : SPACE BAR");
	gotoxy(60, count + 2);
	printf("o ���� : ANY KEY");
}
void ADD(int count, char* name, int score, char* date) // ���Ͽ� ���ο� ������ ���Ѵ�
{
	FILE* fp = fopen("plain.txt", "a");
	if (fp == NULL)
		printf("���� X\n");
	else
		fprintf(fp, "%d\t%s\t%d\t%s\n", ++count, name, score, date);
	fclose(fp);
}
void Delete(guest* gue, int num, int count) // �̸��� ���� ���õ� �����͸� �����Ѵ�.
{
	FILE* fout = fopen("plain.txt", "w");
	for (int i = 0; i < count; i++)
	{
		if (gue[i].num == num)continue;
		fprintf(fout, "%d\t%s\t%d\t%s\n", gue[i].num, gue[i].name, gue[i].score, gue[i].date);
	}
	fclose(fout);
}
void Mileage(guest* gue, guest cus) // �̸��� ���� ���õ� �������� ���ϸ��� ������ �̿��Ͽ� ��ǰ�� ����Ѵ�.
{
	gotoxy(30, 0);
	int score = cus.score;
	int a_count = 0, b_count = 0, c_count = 0, d_count = 0, e_count = 0;
	printf("�� ���ϸ��� ��ǰ");
	gotoxy(17, 1);
	printf("������������������������������������������������������������������������������������������");
	for (int i = 0; i < 5; i++)
	{
		gotoxy(17, 2 + i);
		printf("��");
		gotoxy(61, 2 + i);
		printf("��");
	}
	gotoxy(17, 7);
	printf("������������������������������������������������������������������������������������������");
	gotoxy(19, 2);
	printf("�� 180000 Mileage : Business Class  ");
	gotoxy(19, 3);
	printf("�� 120000 Mileage : Economy Class ");
	gotoxy(19, 4);
	printf("�� 80000  Mileage : Travel Carrier ");
	gotoxy(19, 5);
	printf("�� 30000  Mileage : Free Refreshment ");
	gotoxy(19, 6);
	printf("�� 10000  Mileage : Mascot Doll ");
	gotoxy(1, 8);
	while (score >= 10000)
	{
		if (score >= 180000)
		{
			a_count++;
			score = score - 180000;
		}
		else if (score >= 120000)
		{
			b_count++;
			score = score - 120000;
		}
		else if (score >= 80000)
		{
			c_count++;
			score = score - 80000;
		}
		else if (score >= 30000)
		{
			d_count++;
			score = score - 30000;
		}
		else
		{
			e_count++;
			score = score - 10000;
		}
	}
	gotoxy(13, 9);
	printf("�� %s ������ �̿� �Ͻ� �� �ִ� ��ǰ ����Ʈ �Դϴ�.", cus.name);
	gotoxy(28, 11);
	printf("������������");
	gotoxy(28, 12);
	printf("Business Class   : %d��", a_count);
	gotoxy(28, 13);
	printf("Economy Class    : %d��", b_count);
	gotoxy(28, 14);
	printf("Travel Carrier   : %d��", c_count);
	gotoxy(28, 15);
	printf("Free Refreshment : %d��", d_count);
	gotoxy(28, 16);
	printf("Mascot Doll      : %d��", e_count);
	gotoxy(28, 17);
	printf("������������");
	gotoxy(19, 19);
	printf("��  %s ������ �ܿ� ���ϸ��� : %d", cus.name, score);
	gotoxy(26, 23);
	printf("o Continue : press ANY key");
	gotoxy(26, 24);
	printf("o Exit : press ESC key");
}
void SWAP(guest& a, guest& b, guest c) //������ �̿��ؼ� ���� Swap�Ѵ�.
{
	c = b;
	b = a;
	a = c;
}
int partition(guest* list, int left, int right)
{
	guest pivot, temp = { 0 };
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do
	{
		do
			low++;
		while (low <= right && list[left].priority < pivot.priority);
		do
			high--;
		while (high >= left && list[high].priority > pivot.priority);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}
void quick_sort(guest* list, int left, int right) // ������������ �����ϱ� ���ؼ� quick ������ ���
{
	if (left < right)
	{
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}
void ascending_order(guest* gue, int count) // ������������ ���ĵ� ������ ���ο� ���Ͽ� �����Ѵ�.
{
	FILE* fout = fopen("plain.txt", "w");
	quick_sort(gue, 0, count - 1);
	Base(gue, count);
	for (int i = 0; i < count; i++)
		fprintf(fout, "%d\t%s\t%d\t%s\n", gue[i].num, gue[i].name, gue[i].score, gue[i].date);
	fclose(fout);
}