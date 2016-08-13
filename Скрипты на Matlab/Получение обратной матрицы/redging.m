function M = redging(A) 
	n = size(A);
	for k=1:n
	AK = A(1:k,1:k); % Матрица используемая на данном шаге
	if k == 1
		M(1,1) = 1 / AK(1,1); % Обратная матрица на первом шаге
	else
		KStroka = AK(k,1:k-1); % Крайняя Строка 
		KStolbec = AK(1:k-1,k); % Крайний Столбец 
		akk = AK(k,k); % Крайний элемент
		%Формулы метода окаймления
		a = 1 / (akk - KStroka * M * KStolbec);
		r = (-a) * (M * KStolbec); 
		q = (-a) * KStroka * M; 
		b = M - (M * KStolbec) * q;
		M = [b r; q a]; % Матрица полученная на данном шаге
	end
end