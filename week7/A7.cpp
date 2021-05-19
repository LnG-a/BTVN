#include <iostream>
#include<string>

using namespace std;


int main()
{
	string a, b;
	cin >> a >> b;

	bool check = true;
	int dem = 0;

	for (int i = 0; i < b.size() - a.size() + 1; i++)
	{
		if (b[i] == a[0])
		{
			for (int j = 0; j < a.size(); j++)
			{
				if (b[i + j] != a[j]) check = false;
			}
			if (check == true)
			{
				dem++;
			}
			check = true;
		}
	}
	cout << dem << endl;
	return 0;
}