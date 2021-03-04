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
						if (k == i && l == j) continue;
						if (l - k == j - i) if (ban_co[k][l] == true)return false;
						if (l + k == j + i) if (ban_co[k][l] == true)return false;
					}
				}
			}
		}
	}
	return true;
}

int main()
{
	int n = 5;
	bool u = false;
	bool** ban_co = new bool* [5];
	for (int i = 0; i < n; i++)
	{
		ban_co[i] = new bool[5];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ban_co[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		ban_co[0][i] = true;
	}

	for (int b = 0; b < n; b++)
	{
		ban_co[b][0] = true;
		for (int c = 0; c < n; c++)
		{
			ban_co[c][1] = true;
			for (int d = 0; d < n; d++)
			{
				ban_co[d][2] = true;
				for (int e = 0; e < n; e++)
				{
					ban_co[e][3] = true;
					for (int f = 0; f < n; f++)
					{
						ban_co[f][4] = true;
						if (check_hau(n, ban_co) && u == false)
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									cout << ban_co[i][j] << " ";
								}
								cout << endl;
							}
							cout << endl;
							u = true;
						}
						for (int i = 0; i < n; i++) ban_co[i][4] = false;
					}
					for (int i = 0; i < n; i++) ban_co[i][3] = false;
				}
				for (int i = 0; i < n; i++) ban_co[i][2] = false;
			}
			for (int i = 0; i < n; i++) ban_co[i][1] = false;
		}
		for (int i = 0; i < n; i++) ban_co[i][0] = false;
	}
	return 0;
}