#include<iostream>

using namespace std;

char* weird_string() {
    char c[] = { 1,2,3,4,5 };
    return c;
}

int main()
{
    cout << *(weird_string);
    return 0;
}