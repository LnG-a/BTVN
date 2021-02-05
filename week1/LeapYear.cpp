#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
	int year;
	cin >> year;
	cout << boolalpha;
	if (year % 400 == 0) cout << true;
	else if (year % 100 == 0)cout << false;
	else if (year % 4 == 0)cout << true;
	else cout << false;
	return 0;
}

