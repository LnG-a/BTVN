#include <iostream>

using namespace std;

int main()
{
	int a = 0;
	int* p = &a;
	cout << a;
	delete p;
	cerr << a;
	return 0;
}
//chuong trinh crash co the do truy cap vao o nho da giai phong