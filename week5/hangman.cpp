#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int max_bad_guesses = 10;
const string FIGURE[] = { "fig0","fig1","fig2","fig3","fig4","fig5","fig6","fig7" };

string choose_word()
{
	srand(time(0));
	int a=0;
	string str;
	ifstream infile ("file_word.txt");
	while (!infile.eof())
	{
		getline(infile, str);
		a++;
	}
	infile.close();
	ifstream innfile("file_word.txt");
	int word_count = a-1;
	int random_index = rand() & word_count;
	for (int i = 0; i < random_index; i++)
	{
		getline(innfile, str);
	}
	return str;
}
bool contains(string word, char guess)
{
	if (word.find(guess) == string::npos) return false;
	if (word.find(guess + 32) == string::npos) return false;
	if (word.find(guess - 32) == string::npos) return false;
	return true;
}
void update(string& guessed_word,const string& word,const char& guess)
{
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == guess) guessed_word[i] = guess;
	}
}
void render_game(string guessed_word, int bad_guess, char& guess)
{
	//cout << FIGURE[bad_guess] << endl;
	cout << "The word is: " << guessed_word << endl;
	cout << "Wrong guesses: " << bad_guess << endl;
	cout << "Your guess: " ;
	cin >> guess;
	cout << endl;
	cout << "--------------------------------------------" << endl;
}
int main()
{
	char guess;
	int bad_guess = 0;
	string word = choose_word();
	string guessed_word;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == ' ') {
			guessed_word.append(" ");
		}
		else guessed_word.append("-");
	}
	do
	{	
		render_game(guessed_word, bad_guess, guess);
		if (contains(word, guess)) update(guessed_word, word, guess);
		else bad_guess++;
	} while (bad_guess < max_bad_guesses && word != guessed_word);
	
	if (bad_guess < max_bad_guesses) cout << "YOU WIN!" ;
	else
	{
		//cout << FIGURE[max_bad_guesses] << endl;
		cout << "YOU LOSE";
	}
	cout << endl << "The word is: " << word;
}