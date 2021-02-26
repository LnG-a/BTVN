#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

bool la_nam_nhuan(int year)
{
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) return true;
	return false;
}
bool ngay_hop_le(int day, int month, int year)
{
	if (day < 1) return false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day <= 31) return true;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day <= 30) return true;
	case 2:
		if (day <= 28) return true;
		else if (la_nam_nhuan(year) && day <= 29) return true;
	default: return false;
	}
	return false;
}

int main()
{
	int day, month, year;
	char a, b;
	cin >> day >> a >> month >> b >> year;
	while (!ngay_hop_le(day, month, year))
	{
		cout << "invalid day" << endl;
		cin >> day >> a >> month >> b >> year;
	}
	int k, chenh_lech[100], n = 0;
	do
	{
		cin >> k;
		if (k != 0) chenh_lech[n] = k;
		n++;
	} while (k != 0);
	for (int i = 0; i < n - 1; i++)
	{
		int day_ = day, month_ = month, year_ = year;
		while (chenh_lech[i] > 0)
		{
			chenh_lech[i]--;
			day_++;
			if (!ngay_hop_le(day_, month_, year_))
			{
				if (month_ < 12) { month_++; day_ = 1; }
				else if (month_ == 12) { month_ = 1; day_ = 1; year_++; }
			}
		}
		while (chenh_lech[i] < 0)
		{
			chenh_lech[i]++;
			day_--;
			if (!ngay_hop_le(day_, month_, year_))
			{
				if (month_ > 1)
				{
					month_--;
					day_ = 31;
					while (!ngay_hop_le(day_, month_, year_))
					{
						day_--;
					}
				}
				else if (month_ == 1) { month_ = 12; day_ = 31; year_--; }
			}
		}
		if (day_ < 10) cout << 0 << day_;
		else cout << day_;
		cout << "-";
		if (month_ < 10) cout << 0 << month_;
		else cout << month_;
		cout << "-" << year_ << endl;
	}
	return 0;
}