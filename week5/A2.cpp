#include <iostream>

using namespace std;

int factorial(int x)
{
	cout << "x= " << x << " at " << &x << endl;
	if (x > 1) return x * factorial(x - 1);
	else return 1;
}
int main()
{
	cout << factorial(5);
}
//dia chi lien tiep nhau
//216 bit