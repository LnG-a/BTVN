#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
	double can_nang, chieu_cao;
	cin >> can_nang >> chieu_cao;
	cout << fixed << setprecision(2) << can_nang / (chieu_cao * chieu_cao);
}
