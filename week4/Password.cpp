#include <iostream>
#include <string>

using namespace std;

string reverse(string& word, const int& n)
{
	string reverse = word;
	for (int i = 0; i < n; i++) {
		reverse[i] = word[n - i - 1];
	}
	return reverse;
}

int main()
{
	int n;
	cin >> n;
	string a[100];

	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == reverse(a[j], a[j].length()))
			{
				cout << a[i].length() << " " << a[i][(a[i].length() - 1) / 2];
			}
		}
	}
	return 0;
}