#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	for (int i = 0; i < 24; i++)
	{
		if (i == 0) cout << i << " midnight" << endl;
		if (1 <= i < 12) cout << i << "am" << endl;
		if (i == 12) cout << i << " noon" << endl;
		if (13 <= i) cout << i - 12 << "pm" << endl;
	}
	return 0;
}