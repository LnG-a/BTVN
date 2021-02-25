#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	double k;
	cin >> k;
	while (k >= 3) k /= 3;
	cout << k;
	return 0;
}