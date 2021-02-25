#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

string read_number(int n)
{
	if (n == 0)return "";
	string num;
	int don_vi, chuc, tram;
	don_vi = n % 10;
	n /= 10;
	chuc = n % 10;
	n /= 10;
	tram = n % 10;
	switch (tram)
	{
	case 1:
		num += "one hundred and ";
		break;
	case 2:
		num += "two hundred and ";
		break;
	case 3:
		num += "three hundred and ";
		break;
	case 4:
		num += "four hundred and ";
		break;
	case 5:
		num += "five hundred and ";
		break;
	case 6:
		num += "six hundred and ";
		break;
	case 7:
		num += "seven hundred and ";
		break;
	case 8:
		num += "eight hundred and ";
		break;
	case 9:
		num += "nine hundred and ";
		break;
	default:
		break;
	}
	if (chuc == 1)
	{
		switch (don_vi)
		{
		case 0:
			num += "ten ";
			break;
		case 1:
			num += "eleven ";
		case 2:
			num += "twelve ";
			break;
		case 3:
			num += "thirteen ";
			break;
		case 4:
			num += "fourteen ";
			break;
		case 5:
			num += "fifteen ";
			break;
		case 6:
			num += "sixteem ";
			break;
		case 7:
			num += "seventeen ";
			break;
		case 8:
			num += "eighteen ";
			break;
		case 9:
			num += "nineteen ";
			break;
		default:
			break;
		}
	}
	else
	{
		switch (chuc)
		{
		case 2:
			num += "twenty ";
			break;
		case 3:
			num += "thirty ";
			break;
		case 4:
			num += "fourty ";
			break;
		case 5:
			num += "fifty ";
			break;
		case 6:
			num += "sixty ";
			break;
		case 7:
			num += "seventy ";
			break;
		case 8:
			num += "eighty ";
			break;
		case 9:
			num += "ninety ";
			break;
		default:
			break;
		}
		switch (don_vi)
		{
		case 1:
			num += "one ";
			break;
		case 2:
			num += "two ";
			break;
		case 3:
			num += "three ";
			break;
		case 4:
			num += "four ";
			break;
		case 5:
			num += "five ";
			break;
		case 6:
			num += "six ";
			break;
		case 7:
			num += "seven ";
			break;
		case 8:
			num += "eight ";
			break;
		case 9:
			num += "nine ";
			break;
		}
	}
	return num;
}
int main()
{
	int n;
	int don_vi, nghin, trieu;
	cin >> n;
	if (n < 0)
	{
		cout << "negative ";
		n *= -1;
	}
	don_vi = n % 1000;
	n /= 1000;
	nghin = n % 1000;
	n /= 1000;
	trieu = n % 1000;
	if (trieu != 0) cout << read_number(trieu) << "million ";
	if (nghin != 0) cout << read_number(nghin) << "thousand ";
	if (don_vi != 0)cout << read_number(don_vi);
	else cout << "zero";
	return 0;
}
