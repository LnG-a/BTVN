#include <iostream>
#include <cmath>

using namespace std;

bool la_so_nguyen_to(const int& n)
{
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	if (la_so_nguyen_to(n)) cout << "yes";
	else cout << "no";
	return 0;
}
