#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;



long day(const int& ngay, const int& thang, const int& nam)
{
	long days = 0;
	for (int i = 0; i < nam; i++)
	{
		if (la_nam_nhuan(i)) days += 366;
		else days += 365;
	}
	for (int i = 1; i < thang; i++)
	{
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			days += 31;
			break;
		}
		case 2:
		{
			if (la_nam_nhuan(nam)) days += 29;
			else days += 28;
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			days += 30;
			break;
		}
		}
	}
	days += ngay;
	return days;
}

const long ngay1thang2nam2021 = day(1, 2, 2021);

int main()
{
	int ngay, thang, nam;
	cin >> ngay >> thang >> nam;
	long so_ngay = day(ngay, thang, nam);
	int chenh_lech;
	if (so_ngay > ngay1thang2nam2021)
	{
		chenh_lech = (so_ngay - ngay1thang2nam2021) % 7;
		switch (chenh_lech)
		{
		case 0:
		{
			cout << "Monday" << endl;
			break;
		}
		case 1:
		{
			cout << "Tuesday" << endl;
			break;
		}
		case 2:
		{
			cout << "Wednesday" << endl;
			break;
		}
		case 3:
		{
			cout << "Thursday" << endl;
			break;
		}
		case 4:
		{
			cout << "Friday" << endl;
			break;
		}
		case 5:
		{
			cout << "Saturday" << endl;
			break;
		}
		case 6:
		{
			cout << "Sunday" << endl;
			break;
		}
		}
	}
	else
	{
		chenh_lech = (ngay1thang2nam2021 - so_ngay) % 7;
		switch (chenh_lech)
		{
		case 0:
		{
			cout << "Monday" << endl;
			break;
		}
		case 6:
		{
			cout << "Tuesday" << endl;
			break;
		}
		case 5:
		{
			cout << "Wednesday" << endl;
			break;
		}
		case 4:
		{
			cout << "Thursday" << endl;
			break;
		}
		case 3:
		{
			cout << "Friday" << endl;
			break;
		}
		case 2:
		{
			cout << "Saturday" << endl;
			break;
		}
		case 1:
		{
			cout << "Sunday" << endl;
			break;
		}
		}
	}
	return 0;
}
