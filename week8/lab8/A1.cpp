#include <iostream>
#include<string>

using namespace std;


void f(int xval)
{
	int x;
	x = xval;
	cout << &x << endl;
}
void g(int yval)
{
	int y;
	y = yval;
	cout << &y;

}

int main()
{
	f(7);
	g(11);

	return 0;
}

//dia chi 2 bien giong nhau;
//giai thich: sau khi ket thuc ham f chuong trinh cha bo nho cua bien x ve cho he thong
//he thong tiep tuc dung vi tri day de khoi tao bien y