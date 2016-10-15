#include <iostream>
#include <math.h>

using namespace std;

#define M(line, col) a[(line) * (n + 1) + (col)]

int main() {
	int n;
	cin >> n;

	float *a = (float*)_aligned_malloc(n * (n + 1) * sizeof(float), 16);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= n; ++j)
			cin >> M(i, j);

	for (int i = 0; i < n - 1; ++i) {
		int mx_k = i;
		float mx_lmnt = M(i, i);

		for (int k = i; k < n; ++k)
			if (abs(mx_lmnt) < abs(M(k, i)))
				mx_lmnt = M(mx_k = k, i);

		if (mx_k != i) {
			const int m = n + 1;

			for (int l = i; l < m - 3; l += 4) {
				const float 
					*pa = &M(i, l), 
					*pb = &M(mx_k, l);

				__asm {
					movaps xmm0, pa;
					movaps xmm1, pb;

					movaps pb, xmm0;
					movaps pa, xmm1;
				}
			}

			for (int l = m - (m - i) % 4; l < m; ++l)
				swap(M(i, l), M(mx_k, l));
		}

		for (int k = 1 + i; k < n; ++k) {
			const float tmp = M(k, i) / mx_lmnt;
			for (int l = i; l <= n; ++l)
				M(k, l) -= M(i, l) * tmp;
		}
	}

	float *ans = new float[n];

	for (int k = 1; k <= n; ++k) {
		float tmp = M(n - k, n);
		for (int l = 1; l < k; ++l)
			tmp -= M(n - k, n - l) * ans[n - l];
		ans[n - k] = tmp / M(n - k, n - k);
	}

	for (int i = 0; i < n; ++i)
		cout << ans[i] << endl;

	delete[] ans;
	_aligned_free(a);

	return 0;
}