#include <iostream>

#include <algorithm>

using namespace std;

char* reverse(const char b[])
{
	char* a = new char[100];
	int m = 0;
	while (*(b + m) != '\0')
	{
		m++;
	}

	for (int i = 0; i < m; i++)
	{
		*(a + i) = *(b + i);
	}
	*(a + m) = '\0';

	char* begin = a, * end = a, ch;

	for (int i = 0; i < m - 1; i++)
	{
		end++;
	}

	for (int i = 0; i < m / 2; i++)
	{
		ch = *end;
		*end = *begin;
		*begin = ch;

		begin++;
		end--;
	}
	return a;
}

char* delete_char(const char b[], char c)
{
	char* a = new char[100];
	int m = 0;
	while (*(b + m) != '\0')
	{
		m++;
	}

	for (int i = 0; i < m; i++)
	{
		*(a + i) = *(b + i);
	}
	*(a + m) = '\0';

	for (char* i = a; (*i) != '\0'; i++)
	{
		if (*i == c)
		{
			for (char* j = i; *(j) != '\0'; j++)
			{
				if (*(j + 1) != '\0')
				{
					*j = *(j + 1);
				}
				else
				{
					*j = '\0';
				}
			}
			i--;
		}

	}
	return a;
}

char* pad_right(const char b[], int n)
{
	char* a = new char[100];
	int m = 0;
	while (*(b + m) != '\0')
	{
		m++;
	}

	for (int i = 0; i < m; i++)
	{
		*(a + i) = *(b + i);
	}
	*(a + m) = '\0';

	char* ptr;
	ptr = a;
	for (int i = 0; i < m; i++)
	{
		ptr++;
	}
	while (m < n)
	{
		*ptr = ' ';
		ptr++;
		m++;
	}

	*ptr = '\0';
	return a;
}

char* pad_left(const char b[], int n)
{
	char* a = new char[100];
	int m = 0;
	while (*(b + m) != '\0')
	{
		m++;
	}

	for (int i = 0; i < m; i++)
	{
		*(a + i) = *(b + i);
	}
	*(a + m) = '\0';

	*(a + n) = '\0';

	for (int i = n - 1; i >= n - m; i--)
	{
		*(a + i) = *(a + i - n + m);
	}
	for (int i = 0; i < n - m; i++)
	{
		*(a + i) = ' ';
	}
	return a;
}

char* truncate(const char b[], int n)
{
	char* a = new char[100];
	int m = 0;
	while (*(b + m) != '\0')
	{
		m++;
	}

	for (int i = 0; i < m; i++)
	{
		*(a + i) = *(b + i);
	}
	*(a + m) = '\0';

	if (m > n)
	{
		a[n] = '\0';
	}
	return a;
}

bool is_palindrome(const char a[])
{
	int m = 0;
	while (*(a + m) != '\0')
	{
		m++;
	}

	for (int i = 0; i < m; i++)
	{
		if (*(reverse(a) + i) != *(a + i)) return false;
	}
	return true;

}

char* trim_left(const char b[])
{
	char* a = new char[100];
	int m = 0;
	while (*(b + m) != '\0')
	{
		m++;
	}

	for (int i = 0; i < m; i++)
	{
		*(a + i) = *(b + i);
	}
	*(a + m) = '\0';
	for (char* i = a; (*i) != '\0'; i++)
	{
		if (*i == ' ')
		{
			for (char* j = i; *(j) != '\0'; j++)
			{
				if (*(j + 1) != '\0')
				{
					*j = *(j + 1);
				}
				else
				{
					*j = '\0';
				}
			}
			i--;
		}
		else break;
	}
	return a;
}

char* trim_right(const char b[])
{
	char* a = new char[100];
	int m = 0;
	while (*(b + m) != '\0')
	{
		m++;
	}

	for (int i = 0; i < m; i++)
	{
		*(a + i) = *(b + i);
	}

	for (int i = m - 1; i > 0; i--)
	{
		if (*(a + i) == ' ') {
			*(a + i) = '\0';
		}
		else break;
	}
	return a;
}

int main()
{
	char a[] = " 7 5 7 ";

	cout << is_palindrome(a);

	return 0;
}

