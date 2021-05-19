#include <iostream>
#include<string>

using namespace std;


int main()
{

	int b[4] = { 1,2,3,4 };
	double c[4] = { 1,2,3,4 };
	cout << &b[2] << endl;
	cout << &b[3] << endl;
	for (int* cp = b; (*cp) <= b[3]; cp++) {
		cout << (void*)cp << " : " << (*cp) << endl;

	}
	for (double* cp = c; (*cp) < c[3]; cp += 1) {
		cout << (void*)cp << " : " << (*cp) << endl;

	}
	return 0;
}