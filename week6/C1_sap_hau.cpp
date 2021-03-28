#include <iostream>

using namespace std;

bool check_hau(const int& n, int* x, int* y)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (x[i] == x[j])return false;
			if (y[i] == y[j]) return false;
			if (y[i] - x[i] == y[j] - x[j]) return false;
			if (y[i] + x[i] == y[j] + x[j]) return false;
		}
	}
	return true;
}

void print(const int& n, int* x, int* y)
{
	int u = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + 1 == x[u] && i + 1 == y[u])
			{
				cout << "*" << " ";
				u++;
			}
			else cout << "." << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void sap_hau(const int& n, int* x, int* y, int row)
{

	for (int i = 1; i <= n; i++)
	{
		x[y[row - 1] - 1] = i;
		if (row < n) sap_hau(n, x, y, row + 1);
		else
		{
			if (check_hau(n, x, y))
			{
				print(n, x, y);
			}
		}

	}
}

int main()
{
	int n;
	cin >> n;

	int* x = new int[n];
	int* y = new int[n];

	for (int i = 0; i < n; i++)
	{
		y[i] = i + 1;
	}

	sap_hau(n, x, y, 1);
}