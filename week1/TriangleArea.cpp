#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	double p = (a + b + c) / 2;
	cout << fixed << setprecision(2) << sqrt((p - a) * (p - b) * (p - c) * p);
	return 0;
}