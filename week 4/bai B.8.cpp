#include <iostream>
#include <algorithm>

using namespace std;

bool co_cach_xep(int a[], const int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= a[i + n]) return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n * 2];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cin >> a[i + n];
	}
	sort(a, a + n);
	sort(a + n, a + 2 * n);
	if (co_cach_xep(a, n)) cout << "yes";
	else cout << "no";
	return 0;
}