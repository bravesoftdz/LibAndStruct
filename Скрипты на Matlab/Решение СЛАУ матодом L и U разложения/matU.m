function M = matU(A, B)
n = length(B);
M = zeros(n, 1);
M(n) = B(n) / A(n, n);
for k = n - 1 : -1 : 1
	M(k) = (B(k) - A(k, k + 1 : n) * M(k + 1 : n)) / A(k, k);
end