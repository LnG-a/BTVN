#include <iostream>
#include<string>

using namespace std;

int main() {
	char* s;
	char foo[] = "Hello World";
	s = foo;

	printf("s is %s\n", s);
	cout << "s[0] is " << s[0] << endl;

	return(0);
}