#include <bits/stdc++.h>

long fibonacci_bottomup(long n) {
	if (n <= 1)
		return n;

	std::vector<long> F(n + 1, 0);
	F[0] = 0;
	F[1] = 1;
	
	for (int i = 2; i <= n; ++i)
		F[i] = F[i - 1] + F[i - 2];

	return F[n];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;

	// Caso de prueba 1:
	// Entrada:
	// n = 8
	// Salida:
	// 21
	//
	n = 8;
	std::cout << fibonacci_bottomup(n) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// n = 12
	// Salida:
	// 144
	//
	n = 12;
	std::cout << fibonacci_bottomup(n) << "\n";

	return 0;
}
