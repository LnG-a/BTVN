#include <iostream>

using namespace std;

bool check_hau(const int& n, int* a, int* x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n; j += 2)
		{
			if (i == x[j])
			{
				if (a[i] != -1) return true;
				else a[i] = x[j + 1];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j]) return true;
			if (a[i] - i == a[j] - j) return true;
			if (a[i] + i == a[j] + j) return true;
		}

	}

	return false;
}

int main()
{
	int n;
	cin >> n;

	int* x = new int[2 * n];
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> x[i];
	}
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = -1;
	}

	if (check_hau(n, a, x)) cout << "yes";
	else cout << "no";

	return 0;
}