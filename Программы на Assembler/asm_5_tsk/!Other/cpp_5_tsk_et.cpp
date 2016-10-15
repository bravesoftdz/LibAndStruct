#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	float **a = new float* [n];

	for (int i = 0; i < n; ++i) {
		a[i] = new float[n + 1];
		for (int j = 0; j <= n; ++j)
			cin >> a[i][j]; 
	}

	for (int i = 0; i < n - 1; ++i) {
		int mx_k = i;
		float mx_lmnt = a[i][i];

		for (int k = i; k < n; ++k)
			if (abs(mx_lmnt) < abs(a[k][i]))
				mx_lmnt = a[mx_k = k][i];

		if (mx_k != i)
			for (int l = i; l <= n; ++l)
				swap(a[i][l], a[mx_k][l]);

		for (int k = 1 + i; k < n; ++k) {
			const float tmp = a[k][i] / mx_lmnt;
			for (int l = i; l <= n; ++l)
				a[k][l] -= a[i][l] * tmp;
		}
	}

	float *ans = new float[n];

	for (int k = 1; k <= n; ++k) {
		float tmp = a[n - k][n];
		for (int l = 1; l < k; ++l)
			tmp -= a[n - k][n - l] * ans[n - l];
		ans[n - k] = tmp / a[n - k][n - k];
	}

	for (int i = 0; i < n; ++i)
		cout << ans[i] << endl;

	delete[] ans;
	for (int i = 0; i < n; ++i)
		delete[] a[i];
	delete[] a;
	
	return 0;
}