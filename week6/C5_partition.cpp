#include<iostream>
#include<string>

using namespace std;

void tachTong(int x, int max, string& str, int& tong)

{
    for (int i = max; i >= 1; i--)
    {
        if (tong + i <= x)
        {
            str += to_string(i) + " ";
            tong += i;
            if (tong == x)cout << str << endl;
            else
            {
                tachTong(x, i, str, tong);
            }
            tong -= i;
            str.pop_back();
            str.pop_back();
        }
    }
}
int main()
{
    int n;
    cin >> n;
    string str;
    int tong = 0;
    tachTong(n, n, str, tong);
    return 0;
}