#include<iostream>
#include<string>

using namespace std;

const char a[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

void alphabet(int n, int k, string& str, int first)
{
    for (int i = first; i < n; i++)
    {
        str += a[i];
        if (k == 0) cout << str << endl;
        else alphabet(n, k - 1, str, i + 1);
        str.pop_back();
    }
}
int main()
{
    int n, k;
    cout << "n="; cin >> n;
    cout << "k="; cin >> k;
    string str;
    alphabet(n, k - 1, str, 0);
    return 0;
}