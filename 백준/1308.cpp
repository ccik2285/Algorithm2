#include <iostream>
using namespace std;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear(int year)
{
	if (year % 4 == 0)
		if (year % 100 != 0 || year % 400 == 0)
			return true;

	return false;
}

int dayCount(int y, int m, int d)
{
	int day = 0;
	for (int i = 0; i < y; ++i)
	{
		day += 365;
		if (isLeapYear(i))
			day += 1;
	}

	for (int i = 0; i + 1 < m; ++i)
	{
		if (i == 1)
			day += isLeapYear(y);
		day += month[i];
	}

	day += d;

	return day;
}

int main()
{
	int year_1, month_1, day_1;
	int year_2, month_2, day_2;
	int result, count = 0;
	int day1, day2;

	cin >> year_1 >> month_1 >> day_1;
	cin >> year_2 >> month_2 >> day_2;

	day1 = dayCount(year_1, month_1, day_1);
	day2 = dayCount(year_2, month_2, day_2);

	if (year_2 - year_1 >= 1000 && 
   dayCount(0, month_1, day_1) <= dayCount(0, month_2, day_2))
	{
		cout << "gg";
		return 0;
	}

	cout << "D-" << day2 - day1 << "\n";

	return 0;
}
