function M = gauss(A, B)
	r = rows(A);
	c = columns(A);
	Ag = [A B];
	for k = 1 : r
		if(k < r)
			[z, num] = max(Ag(k : c, k));
			tmp = Ag(num + k - 1, :);
			Ag(num + k - 1, :) = Ag(k, :);
			Ag(k, :) = tmp;
		end
		if (Ag(k, k) == 0)
			disp('Ошибка: Деление на ноль')
			return
		end
		Ag(k, :) = Ag(k, :) / Ag(k, k);
		for i = k + 1 : c
			Ag(i, :) = Ag(i, :) - Ag(k, :) * Ag(i, k);
		end
	end
	
	M = Ag(end,end);
	for k = r - 1 : -1 : 1
		M = [Ag(k, c + 1) - sum(Ag(k, c - (length(M) - 1) : c) * M); M];
	end
end