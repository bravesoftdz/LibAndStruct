function M = rgiv(A, B)
	[Q, R] = qrgiv(A);
	M = matU(R, (Q' * B));
end