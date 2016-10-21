#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class String {
private:
	char *str;
public:
	String(char ch) { str = new char[2]; str[0] = ch; str[1] = '\0'; }
	String(char* _str = "") { str = new char[strlen(_str) + 1]; strcpy(str, _str); };
	String(const String &rhs) { str = new char[strlen(rhs.str) + 1]; strcpy(str, rhs.str); };

	~String() { delete str; };

	String& operator = (const String&);
	friend String operator + (const String &lhs, const String &rhs) { String ts = lhs; return ts += rhs; };
	friend String operator - (const String &lhs, const String &rhs) { String ts = lhs; return ts -= rhs; };
	friend String operator - (const String&, unsigned n);
	String& operator += (const String&);
	String& operator -= (const String&);
	String operator ~();

	friend bool operator == (const String &lhs, const String &rhs) { return strlen(lhs.str) == strlen(rhs.str); };

	friend std::ostream& operator << (std::ostream &os, const String &obj) { return os << obj.str; };
	friend std::istream& operator >> (std::istream&, String&);
};

