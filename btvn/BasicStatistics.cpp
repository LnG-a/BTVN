#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	double a[50], tong = 0, max, min;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	max = a[0];
	min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)max = a[i];
		if (a[i] < min)min = a[i];
		tong += a[i];
	}
	cout << "Mean: " << tong / 3 << endl;
	cout << "Max: " << max << endl;
	cout << "Min: " << min;
}