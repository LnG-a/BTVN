#include<iostream>
#include<iomanip>

using namespace std;

int** Hadamard_function(int** a, int size, int** hadamard)
{
    if (size <= 2)
    {
        return hadamard;
    }
    else
    {
        for (int i = 0; i < size / 2; i++)
        {
            for (int j = 0; j < size / 2; j++)
            {
                a[i][j] = Hadamard_function(a, size / 2, hadamard)[i][j];
                a[i + size / 2][j] = Hadamard_function(a, size / 2, hadamard)[i][j];
                a[i][j + size / 2] = Hadamard_function(a, size / 2, hadamard)[i][j];
                a[i + size / 2][j + size / 2] = Hadamard_function(a, size / 2, hadamard)[i][j] * -1;
            }
        }
        return a;
    }
}
void print(int** a, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (a[i][j] == 1) cout << setw(2) << 'o';
            else cout << setw(2) << ".";
        }
        cout << endl;
    }
}

int main()
{
    int n, size = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        size *= 2;
    }

    int** a = new int* [size];
    for (int i = 0; i < size; i++)
    {
        a[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            a[i][j] = 0;
        }
    }


    int** b = new int* [2];
    for (int i = 0; i < 2; i++)
    {
        b[i] = new int[2];
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            b[i][j] = -1;
        }
    }
    b[1][1] = 1;

    print(Hadamard_function(a, size, b), size)
    return 0;
}