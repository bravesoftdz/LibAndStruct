function GenMatrixTests(count)
	slng = int2str(length(int2str(count)));
	formatStr = strcat('%0', slng, 'u');
	for i = 1 : count
		A = round(rand(i) * 1998 - 999); 
		B = round(diag(rand(i) * 1998 - 999));
		C = [A, B];
		s = strcat('g', num2str(i, formatStr));

		sin = strcat(s, '.in')
		dlmwrite(sin, i);
		dlmwrite(sin, C, ' ', '-append');

		dlmwrite(strcat(s, '.et'), A \ B);
	end
end