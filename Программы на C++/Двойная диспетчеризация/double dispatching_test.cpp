#include "double dispatching.h"
#include <iostream>

using namespace std;

int main() {

	Army *us = new USA;
	Army *ru = new Russia;
	Army *ch = new China;

	cout << "TEST 1 ";

	if (Battle(us, ru) == "USA vs Russia" &&
		Battle(ch, ch) == "China vs China" &&
		Battle(ru, ch) == "Russia vs China")
		cout << "OK";
	else
		cout << "ERROR";

	cout << endl;

	system("PAUSE");

	return 0;
}