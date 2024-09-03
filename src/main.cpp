#include <iostream>
#include "inc/language.h"
#include "inc/shogi.h"

using namespace std;

int main () {
	
	switch (currentLanguage) {
		case ENG:
			cout << en_title << endl;
			break;
		case JPN:
			cout << jp_title << endl;
			break;
	}

	printBoard();

	return 0;
}
