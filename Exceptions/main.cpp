//Daniel Stoddard
//CIS 1202 - 800
//November 28, 2021

#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

char character(char, int);

class invalidCharacterException{};
class invalidRangeException{};

int main() {
	const int amt = 5;
	char letter;
	char tests[][amt] = { {'a', 'a', 'Z', '?', 'A'},{1, -1, -1, 5, 32} };

	for (int x = 0; x < amt; x++) {
		try {
			letter = character(tests[0][x], tests[1][x]);
			cout << letter << endl;
		}
		catch (invalidCharacterException) {
			cout << "INVALID CHARACTER!" << endl;
		}
		catch (invalidRangeException) {
			cout << "INVALID RANGE!" << endl;
		}
	}
	return 0;
}

char character(char start, int offset) {
	if (!isalpha(start)) {
		throw invalidCharacterException();
	}
	else if (!isalpha(tolower(start) + offset)) {
		throw invalidRangeException();
	}
	return start + offset;
}