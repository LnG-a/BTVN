#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
	string a, b, c;
	b = "a";
	c = "b";
	for (int i = 0; i <= 10; i++)
	{
		a = b;
		b = c;
		c = a + b;
		cout << a << endl;
	}
	return 0;
}

