#include <bits/stdc++.h>

long fibonacci(long n) {
	if (n <= 1)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
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
	std::cout << fibonacci(n) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// n = 12
	// Salida:
	// 144
	//
	n = 12;
	std::cout << fibonacci(n) << "\n";

	return 0;
}
