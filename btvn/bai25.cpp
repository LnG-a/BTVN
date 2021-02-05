#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	int a[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}
	int the_median;
	int the_lower1 = a[0], the_lower2 = a[2], the_higher1 = a[0], the_higher2 = a[2], the_higher3, the_lower3;
	if (a[0] < a[1]) the_higher1 = a[1];
	else the_lower1 = a[1];
	if (a[2] < a[3]) the_higher2 = a[3];
	else the_lower2 = a[3];
	if (the_lower1 > the_lower2)
	{
		if (a[4] < the_higher2)
		{
			the_lower3 = a[4];
			the_higher3 = the_higher2;
		}
		else
		{
			the_lower3 = the_higher2;
			the_higher3 = a[4];
		}
		if (the_lower1 > the_lower3)
		{
			if (the_higher3 < the_lower1) the_median = the_higher3;
			else the_median = the_lower1;
		}
		else
		{
			if (the_higher1 > the_lower3) the_median = the_lower3;
			else the_median = the_higher1;
		}
	}
	else
	{
		if (a[4] < the_higher1)
		{
			the_lower3 = a[4];
			the_higher3 = the_higher1;
		}
		else
		{
			the_lower3 = the_higher1;
			the_higher3 = a[4];
		}
		if (the_lower2 > the_lower3)
		{
			if (the_higher3 < the_lower2) the_median = the_higher3;
			else the_median = the_lower2;
		}
		else
		{
			if (the_higher2 > the_lower3) the_median = the_lower3;
			else the_median = the_higher2;
		}
	}
	cout << the_median;

}