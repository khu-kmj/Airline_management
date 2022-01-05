#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "AirLine.h"
typedef struct Date
{
	int year, month, day;
}Date;
int DayDifference(Date d1, Date d2) // 윤년을 고려한 d1과 d2의 일수 차이
{
	int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i;
	int days1 = 0, days2 = 0;

	for (i = 1900; i <= d1.year - 1; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
			days1 += 366;
		else days1 += 365;
	}
	for (i = 0; i < d1.month - 1; i++)
	{
		if (i == 1)
		{
			if (((d1.year % 4 == 0) && (d1.year % 100 != 0)) || (d1.year % 400 == 0))
				days1 += 29;
			else days1 += 28;
		}
		else
			days1 += month_days[i];
	}
	days1 += d1.day;
	for (i = 1900; i <= d2.year - 1; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
			days2 += 366;
		else days2 += 365;
	}
	for (i = 0; i < d2.month - 1; i++)
	{
		if (i == 1)
		{
			if (((d2.year % 4 == 0) && (d2.year % 100 != 0)) || (d2.year % 400 == 0))
				days2 += 29;
			else days2 += 28;
		}
		else
			days2 += month_days[i];
	}
	days2 += d2.day;
	return days1 - days2;
}
int MAX_MAI(guest* gue, int count) //마일리지의 최대값을 return 한다
{
	int max = gue[0].score;
	for (int i = 1; i < count; i++)
		if (max < gue[i].score)
			max = gue[i].score;
	return max;
}
int MAX_DAY(int* arr, guest* gue, int count) //현재날짜와의 차이가 가장 큰 값을 return 한다.
{
	time_t timer;
	struct tm* t;
	char temp[20];
	char* token;
	int mon;
	int year;
	int day;
	timer = time(NULL);
	t = localtime(&timer);
	Date d1 = { t->tm_year + 1900, t->tm_mon + 1, t->tm_mday };
	for (int i = 0; i < count; i++)
	{
		strcpy(temp, gue[i].date);
		int check = 0;
		token = strtok(temp, "-");
		year = atoi(token);
		while (token = strtok(NULL, "-"))
		{
			if (check == 0) {
				mon = atoi(token);
				check++;
			}
			else
				day = atoi(token);
		}
		Date d2 = { year, mon, day };
		arr[i] = DayDifference(d1, d2);
	}
	int max = arr[0];
	for (int i = 1; i < count; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}
void Priority(guest* gue, int* arr, int c_max, int d_max, int count) // 우선순위를 구하여 gue구조체 함수의 실수형 priority에 입력한다.
{
	for (int i = 0; i < count; i++)
	{
		float a = gue[i].num - gue[i].score / (float)c_max * 10 - arr[i] / (float)d_max * 5;
		gue[i].priority = a;
	}
}