#include <bits/stdc++.h>

int tiling_memoized(int n, std::vector<int>& memo) {
	if (memo[n])
		return memo[n];

	int result;
	if (n <= 1)
		result = n;
	else
		result = tiling_memoized(n - 1, memo) + tiling_memoized(n - 2, memo);
	
	memo[n] = result;
	return result;
}

int tiling(int n) {
	std::vector<int> memo(n + 1, 0);
	return tiling_memoized(n, memo);
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
	n = 8;
	std::cout << tiling(n) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// n = 12
	// Salida:
	// 144
	n = 12;
	std::cout << tiling(n) << "\n";

	return 0;
}
