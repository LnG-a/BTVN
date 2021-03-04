#include <iostream>

using namespace std;

bool check_array(int* a, const int& n)
{
	int sum_left = 0;
	int sum_right = 0;
	for (int i = 0; i < n; i++) sum_left += a[i];
	for (int i = 0; i < n; i++)
	{
		sum_left -= a[i];
		if (sum_left == sum_right) return true;
		sum_right += a[i];
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	bool u[100];

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		int* a = new int[m];
		for (int j = 0; j < m; j++) cin >> a[j];
		if (check_array(a, m)) u[i] = true;
		else u[i] = false;
	}

	for (int i = 0; i < n; i++)
	{
		if (u[i]) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}