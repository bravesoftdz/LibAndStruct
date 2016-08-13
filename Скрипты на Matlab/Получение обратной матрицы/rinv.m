function M = rinv(A)
	r = rows(A);
	M = [];
	for i = 1 : r
		zr = zeros(r,1);
		zr(i) = 1;
		M = [M gauss(A, zr)];
	end
end