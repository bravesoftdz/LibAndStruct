#include "string_library.h"

String String::operator ~() {
	char *ts = new char[strlen(str) + 1];

	for (size_t i = 1; i <= strlen(str); i++)
		ts[strlen(str) - i] = str[i - 1];
	ts[strlen(str)] = '\0';

	return ts;
}

String operator - (const String &lhs, unsigned n) {
	char *ts = new char[strlen(lhs.str)];

	size_t k = 0;
	for (size_t i = 0; i < strlen(lhs.str); i++)
		if (i != (n - 1)) ts[k++] = lhs.str[i];
	ts[k] = '\0';

	return ts;
};

String& String::operator -= (const String& ths) { 
	size_t k = 0, len = strlen(str);
	for (size_t i = 0, j; i < len; i++) {
		for (j = 0; j < strlen(ths.str) && str[i] != ths.str[j]; j++);
		if (str[i] != ths.str[j]) str[k++] = str[i];
	}

	str[k++] = '\0';
	char *ts = new char[k]; 
	strcpy(ts, str);
	delete[] str;
	str = ts;

	return *this;
}

String& String::operator = (const String& rhs) {
	if (this == &rhs) return *this;

	delete[] str;
	str = new char[strlen(rhs.str) + 1];
	strcpy(str, rhs.str); 
	return *this;
}
 
String& String::operator += (const String& rhs) {
	size_t sz = strlen(str) + strlen(rhs.str); 
	char* ts = new char[sz + 1];

	for (size_t i = 0; i < strlen(str); i++) ts[i] = str[i];
	for (size_t ii = strlen(str), j = 0; ii <= sz; ii++, j++) ts[ii] = rhs.str[j];

	delete[] str;
	str = ts;

	return *this;
}

std::istream& operator >> (std::istream& is, String& obj) {
	char BUFF[2048];

	is.getline(BUFF, sizeof BUFF);
	obj = BUFF;

	return is;
}