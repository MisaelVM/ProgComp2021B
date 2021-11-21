#include <bits/stdc++.h>

long fibonacci_memoized(long n, std::vector<long>& memo) {
	if (memo[n])
		return memo[n];

	int result = 0;
	if (n <= 1)
		result = n;
	else
		result = fibonacci_memoized(n - 1, memo) + fibonacci_memoized(n - 2, memo);
	
	memo[n] = result;
	return result;
}

long fibonacci(long n) {
	std::vector<long> memo(n + 1, 0);
	return fibonacci_memoized(n, memo);
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
