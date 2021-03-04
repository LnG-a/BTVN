#include <iostream>
#include <string>

using namespace std;

int main()
{
	string dictionary;
	cin >> dictionary;
	int n = dictionary.length();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = -1; k < n; k++)
			{
				cout << dictionary[i] << dictionary[j];
				if (k == -1) cout << " ";
				else cout << dictionary[k] << " ";
			}
		}
	}
	return 0;
}