#include <iostream>

#include <algorithm>

using namespace std;

char* concat(const char* a, const char* b)
{
	char* c = new char[100];
	int i = 0, j = 0;
	while (*(a + i) != '\0')
	{
		*(c + i) = *(a + i);
		i++;
	}
	while (*(b + j) != '\0')
	{
		*(c + i + j) = *(b + j);
		j++;
	}
	*(c + i + j) = '\0';
	return c;
}

int main()
{
	cout << concat("hello", "world");
	return 0;
}