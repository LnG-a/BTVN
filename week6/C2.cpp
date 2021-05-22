#include<iostream>
#include<string>

using namespace std;

const char a[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

bool check(string b, int n)
{
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == a[n])
        {
            return false;
        }
    }
    return true;
}

void alphabet(int n, int k, string& str)
{
    for (int i = 0; i < n; i++)
    {
        while (!check(str, i))
        {
            i++;
        }
        if (i >= n)
        {
            continue;
        }
        str += a[i];
        if (k == 0) cout << str << endl;
        else alphabet(n, k - 1, str);
        str.pop_back();
    }
}
int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    string str;
    if (k > 0)
    {
        alphabet(n, k - 1, str);
    }

    return 0;
}