#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	for (int i = 1; i <= 100; i++)
		cout << i << endl;
	int i = 1;
	while (i <= 100)
	{
		cout << i << endl;
		i++;
	}
	i = 1;
	do
	{
		cout << i << endl;
		i++;
	} while (i <= 100);
}