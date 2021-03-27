#include<iostream>
#include<string>

using namespace std;

const char a[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

void alphabet(int n, int k, string& str)
{
    for (int i = 0; i < n; i++)
    {
        str += a[i];
        if (k == 0) cout << str << endl;
        else alphabet(n, k - 1, str);
        str.pop_back();
    }
}
int main()
{
    int n, k;
    cout << "n="; cin >> n;
    cout << "k="; cin >> k;
    string str;
    alphabet(n, k - 1, str);
    return 0;
}