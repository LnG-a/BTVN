#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

void ve_tam_giac(const int& n)
{
	int j;
	int dau_cach = 0;
	for (int i = 1; i <= n; i++)
	{
		for (j = 0; j < dau_cach; j++) cout << " ";
		while (j < n)
		{
			cout << "*";
			j++;
		}
		cout << endl;
		dau_cach++;
	}
}

int main()
{
	int n;
	cin >> n;
	ve_tam_giac(n);
}
