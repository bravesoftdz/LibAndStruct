function M = rlu(A, B) 
	s = size(A);
	L = zeros(s);
	U = eye(s);
	if (det(A) == 0)
		disp('Ошибка: нулевой определитель')
		return 
	end
	for i = 1 : s,
		for j = 1 : s,
			if i>=j
				sm1 = 0;
				for k = 1 : j-1,
					sm1 = sm1 + L(i,k) * U(k,j);
				end
				L(i,j) = A(i,j) - sm1;
			else
				sm2 = 0;
				for k = 1 : i-1,
					sm2 = sm2 + L(i,k) * U(k,j);
				end
				U(i,j) = (1/L(i,i)) * (A(i,j) - sm2);
			end
		end
	end
	
	M = matU(U, matL(L, B));
end