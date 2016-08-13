function M = matU(A, B)
n = length(B);
M = zeros(n, 1);
M(1) = B(1) / A(1, 1);
for k = 2 : n
	M(k) = (B(k) - A(k, 1 : k - 1) * M(1 : k - 1)) / A(k, k);
end
