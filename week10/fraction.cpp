#include "fraction.h"

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
	std::cout << a << "/" << b;
}
