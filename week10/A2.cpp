#include<iostream>

using namespace std;

class fraction
{
public:
	fraction(int a_, int b_);
	~fraction();
	int a, b;
	void print();
private:

};

fraction::fraction(int a_, int b_)
{
	a = a_;
	b = b_;
}

fraction::~fraction()
{
}

void fraction::print()
{
	cout << a << "/" << b;
}

int main()
{
	fraction a = fraction(1, 2);
	a.print();
	return 0;
}
