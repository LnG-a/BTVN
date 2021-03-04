#include <iostream>

using namespace std;

bool check_hau(const int& n, int* x, int* y)
{
	int k, l;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (x[i] = x[j])return true;
			if (y[i] = y[j]) return true;
			if (y[i] - x[i] == y[j] - x[j]) return true;
			if (y[i] + x[i] == y[j] + x[j]) return true;
		}
	}
	return false;
}

int main()
{
	int n;
	cin >> n;

	int* x = new int[n];
	int* y = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}

	if (check_hau(n, x, y)) cout << "yes";
	else cout << "no";

	return 0;
}