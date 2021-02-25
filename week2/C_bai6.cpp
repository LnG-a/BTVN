#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;
	int j, h;
	for (int i = 1; i <= n; i++)
	{
		for (j = i; j <= n; j++)
		{
			cout << j << " ";
		}
		for (h = 1; h < i; h++)
		{
			cout << h << " ";
		}
		cout << endl;
	}
	return 0;
}
