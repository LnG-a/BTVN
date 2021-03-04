#include <iostream>

using namespace std;

bool check_hau(const int& n, bool** ban_co)
{
	int k, l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ban_co[i][j] == true)
			{
				for (int k = 0; k < n; k++)
				{
					if (k == i) continue;
					if (ban_co[k][j] == true) return false;
				}
				for (int k = 0; k < n; k++)
				{
					if (k == j) continue;
					if (ban_co[i][k] == true) return false;
				}
				for (int k = 0; k < n; k++)
				{
					for (int l = 0; l < n; l++)
					{
						if (l == k + j - i) if (ban_co[k][l] == true)return false;
						if (l == -k + j + i) if (ban_co[k][l] == true)return false;
					}
				}
			}
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n * 2];
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> a[i];
	}

	bool** ban_co = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		ban_co[i] = new bool[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ban_co[i][j] = false;
		}
	}

	for (int i = 0; i < 2 * n; i += 2)
	{
		ban_co[a[i]][a[i + 1]] = true;
	}

	if (check_hau(n, ban_co)) cout << "no";
	else cout << "yes";

	return 0;
}