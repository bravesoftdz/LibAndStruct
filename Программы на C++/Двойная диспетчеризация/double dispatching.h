#pragma once

#include <string>

using namespace std;

struct USA;
struct Russia;
struct China;

struct Army {
	virtual string Attack(Army *x) = 0;
	virtual string Attack(USA *x) = 0;
	virtual string Attack(Russia *x) = 0;
	virtual string Attack(China *x) = 0;
};

struct USA : public Army {
	string Attack(Army *x) { return x->Attack(this); }
	string Attack(USA *x) { return "USA vs USA"; };
	string Attack(Russia *x) { return "Russia vs USA"; };
	string Attack(China *x) { return "China vs USA"; };
};

struct Russia : public Army {
	string Attack(Army *x) { return x->Attack(this); }
	string Attack(USA *x) { return "USA vs Russia"; };
	string Attack(Russia *x) { return "Russia vs Russia"; };
	string Attack(China *x) { return "China vs Russia"; };
};

struct China : public Army {
	string Attack(Army *x) { return x->Attack(this); }
	string Attack(USA *x) { return "USA vs USA"; };
	string Attack(Russia *x) { return "Russia vs China"; };
	string Attack(China *x) { return "China vs China"; };
};

string Battle(Army *a1, Army *a2) {
	return a1->Attack(a2);
}