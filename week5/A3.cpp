#include<iostream>
using namespace std;
int c1(int a) {
    cout << "a1->" << &a << endl;
    return a;
}

int c2(int& a) {
    cout << "a2->" << &a << endl;
    return a;
}

int main() {
    int x; cin >> x;
    cout << "x->" << &x << endl;
    cout << c1(x) << endl;
    cout << c2(x);
    return 0;
}
// dia chi cua tham so khi truyen theo kieu pass-by-value khac voi dia chi cua doi so
// dia chi cua tham so khi truyen theo kieu pass-by-reference giong voi dia chi cua doi so