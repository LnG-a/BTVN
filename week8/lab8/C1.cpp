#include <iostream>

#include <algorithm>

using namespace std;

void reverse(char a[])
{
	int n = 0;
	for (char* i = a; (*i) != '\0'; i++)
	{
		n++;
	}

	char* begin = a, * end = a, ch;

	for (int i = 0; i < n - 1; i++)
	{
		end++;
	}

	for (int i = 0; i < n / 2; i++)
	{
		ch = *end;
		*end = *begin;
		*begin = ch;

		begin++;
		end--;
	}
}

void delete_char(char a[], char c)
{

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
}

void pad_right(char a[], int n)
{
	int m = 0;
	for (char* i = a; (*i) != '\0'; i++)
	{
		m++;
	}
	m--;
	char* ptr;
	ptr = a;
	for (int i = 0; i < m; i++)
	{
		ptr++;
	}
	while (m < n)
	{
		ptr++;
		*ptr = ' ';
		m++;
	}
	ptr++;
	*ptr = '\0';
}

void pad_left(char a[], int n)
{
	int m = 0;
	for (char* i = a; (*i) != '\0'; i++)
	{
		m++;
	}

	*(a + n) = '\0';

	for (int i = n - 1; i >= n - m; i--)
	{
		*(a + i) = *(a + i - n + m);
	}
	for (int i = 0; i < n - m; i++)
	{
		*(a + i) = ' ';
	}


}

void truncate(char a[], int n)
{
	int m = 0;
	for (char* i = a; (*i) != '\0'; i++)
	{
		m++;
	}
	if (m > n)
	{
		a[n] = '\0';
	}
}

bool is_palindrome(char a[])
{
	int m = 0;
	for (char* i = a; (*i) != '\0'; i++)
	{
		m++;
	}
	char* b = new char[100];
	*(b + m) = '\0';

	for (int i = 0; i < m; i++)
	{
		*(b + i) = *(a + i);
	}

	reverse(b);
	for (int i = 0; i < m; i++)
	{
		if (*(b + i) != *(a + i)) return false;
	}
	return true;

}

void trim_left(char a[])
{
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
}

void trim_right( char a[])
{	
	
	int m = 0;
	for (char* i = a; (*i) != '\0'; i++)
	{
		m++;
	}

	for (int i = m - 1; i > 0; i--)
	{
		if (*(a + i) == ' ') {
			*(a + i) = '\0';
		}
		else break;
	}
	
}
int main()
{
	char a[] = "  3 5 7  ";


	return 0;
}

