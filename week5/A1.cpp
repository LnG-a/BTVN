#include <iostream>

using namespace std;

int main()
{
	int* a = new int[3];
	char* b = new char[3];
	cout << &a[0] << " " << &a[1] << " " << &a[2] << endl;
	cout << (void*)&b[0] << " " << (void*)&b[1] << " " << (void*)b[2];
	return 0;
}
//dia chi lien tiep nhau