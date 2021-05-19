#include <iostream>

using namespace std;

int main()
{
	int* p = new int;
	int* p2 = p;
	*p = 10;
	cout << p << endl;
	delete p; //dong code gay loi truy cap vao o nho da duoc giai phong
	cout << *p2 << endl;
	delete p2;
	return 0;
}

