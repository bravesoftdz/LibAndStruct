#include <iostream>
#include <iomanip> 
#include <string>
#include <cmath>

using namespace std;

long double fact(int n) {
	return n == 0 ? 1 : n * fact(n - 1);
}

long double func(int n) {
	return pow(-1., n) / fact(2 * n);
}

long double series(long double eps) {
	double sum = 0, psum;
	int i = 1;

	do {
		psum = sum;
		sum += fabs(func(i++));
	} while (fabs(sum) - fabs(psum) > eps);

	return sum;
}

int main() {
	string eps_s;
	long double eps;
	unsigned len;

	cout << "Enter eps: "; cin >> eps_s;

	if (eps_s.find('.') == -1) {
		eps = 0.1;
		len = 1;
	} else {
		eps = atof(eps_s.c_str());
		len = eps_s.length() - eps_s.find('.') - 1;
	}

	cout << "Sum series = " << setprecision(len) << series(eps) << endl;

	return 0;
}