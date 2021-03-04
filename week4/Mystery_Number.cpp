#include <iostream>

using namespace std;

void xoa_phan_tu(int* arr, const int& pos, int& m)
{
	for (int i = pos; i < m - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	m--;
}

int main()
{
	int n;
	cin >> n;
	int m = n + 1;
	int* a = new int[n];
	int* b = new int[n + 1];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				xoa_phan_tu(b, j, m);
				j--;
				break;
			}
		}
	}
	cout << b[0];
	return 0;
}