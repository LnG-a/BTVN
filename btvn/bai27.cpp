#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	while (n != -1)
	{
		if (n % 5 == 0 && n >= 0) cout << n / 5 << endl;
		else cout << -1 << endl;
		if (n == -1)cout << "Bye";
		cin >> n;
	}
}