function M = rmgh(A, B)
	[Q, R] = qrmgh(A);
	M = matU(R, (Q' * B));
end