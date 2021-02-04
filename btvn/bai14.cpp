#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
	int a, b, so_lan_dung = 0;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		a = rand() % 101;
		b = rand() % 101;
		cout << a << endl << b << endl;
		if (a >= 50)
		{
			cout << "Bob choose: " << a;
			if (a >= b) so_lan_dung++;
		}
		else
		{
			cout << "Bob choose: " << b;
			if (b >= a) so_lan_dung++;
		}
		cout << endl;
	}
	cout << "so lan Bob chon dung la: " << so_lan_dung;
}
