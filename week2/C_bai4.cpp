#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

void ve_tam_giac(const int& n)
{
	int j;
	int u = n;
	int dau_cach = 0;
	for (int i = 0; i <= n / 2; i++)
	{
		for (j = 0; j < dau_cach; j++) cout << " ";
		while (j < u)
		{
			cout << "*";
			j++;
		}
		cout << endl;
		dau_cach++;
		u--;
	}
}

int main()
{
	int n;
	cin >> n;
	ve_tam_giac(n * 2 - 1);
	return 0;
}
