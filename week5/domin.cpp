#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
const int width_of_a_square = 3;
const int digged = -3;
const int not_be_digged = -2;
const int there_is_a_bomb_here = -1;

void createField(int** field, int m, int n, int mine)
{
	srand(time(0));
	while (mine > 0) {
		int tmp1, tmp2;
		tmp1 = rand() % m;
		tmp2 = rand() % n;
		if (field[tmp1][tmp2] != -1)
		{
			field[tmp1][tmp2] = there_is_a_bomb_here;
			mine--;
		}
	}
}

int number_of_bomb(int** field, int m, int n, int x, int y)
{
	int bomb = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < m)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (j >= 0 && j < n)
				{
					if (i == x && j == y) continue;
					if (field[i][j] == there_is_a_bomb_here) bomb++;
				}
			}
		}
	}

	return bomb;
}

void update_field(int** field, int m, int n, int x, int y)
{
	for (int i = x - 1; i <= x + 1; i++)
	{
		if (i >= 0 && i < m)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (j >= 0 && j < n)
				{
					if (i == x && j == y) continue;
					if (field[i][j] == not_be_digged)
					{
						field[i][j] = number_of_bomb(field, m, n, i, j);
						if (field[i][j] == 0) update_field(field, m, n, i, j);
					}
				}
			}
		}
	}

}

void printField(int** field, int m, int n, int x, int y)
{
	for (int i = 0; i < 60; i++) cout << endl;
	bool need_to_update = false;
	cout << setw(width_of_a_square * 2 - 1) << ' ';
	for (int i = 0; i < n; i++) {
		cout << setw(width_of_a_square) << i + 1;
	}
	cout << endl << endl;
	for (int i = 0; i < m; i++) {
		cout << setw(width_of_a_square) << i + 1;
		cout << setw(width_of_a_square - 1) << "";
		for (int j = 0; j < n; j++) {
			if (field[i][j] == there_is_a_bomb_here || field[i][j] == not_be_digged) cout << setw(width_of_a_square) << '-';
			else if (field[i][j] == digged)
			{
				field[i][j] = number_of_bomb(field, m, n, x, y);
				if (field[i][j] == 0) need_to_update = true;
				cout << setw(width_of_a_square) << field[i][j];
			}
			else cout << setw(width_of_a_square) << field[i][j];
		}
		cout << endl;
	}
	if (need_to_update)
	{
		update_field(field, m, n, x, y);
		printField(field, m, n, x, y);
		need_to_update = false;
	}
}

void printMine(int** field, int m, int n)
{
	for (int i = 0; i < 60; i++) cout << endl;
	cout << setw(width_of_a_square * 2 - 1) << ' ';
	for (int i = 0; i < n; i++) {
		cout << setw(width_of_a_square) << i + 1;
	}
	cout << endl << endl;
	for (int i = 0; i < m; i++) {
		cout << setw(width_of_a_square) << i + 1;
		cout << setw(width_of_a_square - 1) << "";
		for (int j = 0; j < n; j++) {
			if (field[i][j] == there_is_a_bomb_here) cout << setw(width_of_a_square) << 'x';
			else if (field[i][j] == not_be_digged) cout << setw(width_of_a_square) << '-';
			else cout << setw(2) << field[i][j];
		}
		cout << endl;
	}
	cout << "YOU ARE DEAD !" << endl;
}

void checkMine(int** field, int m, int n, int safePlace)
{
	int alive = 1;
	while (alive == 1 && safePlace > 0) {
		cout << "Please type in the position you want to dig : ";
		int x, y;
		cin >> y >> x;
		while (x > m || y > n)
		{
			cout << "Invalid input, please try again : ";
			cin >> y >> x;
		}
		x--; y--;
		if (field[x][y] == not_be_digged)
		{
			field[x][y] = digged;
			printField(field, m, n, x, y);
			cout << "That's a safe place" << endl;
		}
		else if (field[x][y] == there_is_a_bomb_here) {

			alive = 0;
			printMine(field, m, n);
		}
		else
		{
			cout << "You have already dig here" << endl;
			continue;
		}
	}
	if (safePlace == 0) cout << "YOU ARE WINNER !!";
}

int main()
{
	cout << "WELCOME TO PROTO MINESWEEPER !" << endl;
	int m, n;
	cout << "Number of rows: ";
	cin >> m;
	while (m <= 0)
	{
		cout << "Invalid input, please fill in again : ";
		cin >> m;
	}

	cout << "Number of columns: ";
	cin >> n;
	while (n <= 0)
	{
		cout << "Invalid input, please fill in again : ";
		cin >> n;
	}

	cout << "Mine : ";
	int K;
	cin >> K;
	while (K <= 0 || K > m * n) {
		cout << "Invalid input, please fill in again : ";
		cin >> m;
	}

	int** field = new int* [m];
	for (int i = 0; i < n; i++)
	{
		field[i] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			field[i][j] = not_be_digged;
		}
	}

	createField(field, m, n, K);

	printField(field, m, n, 0, 0);

	int safePlace = m * n - K;

	checkMine(field, m, n, safePlace);
	return 0;
}
