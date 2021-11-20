#include <bits/stdc++.h>

int uniquePaths_memoized(int m, int n, std::vector<std::vector<int>>& memo) {
	if (memo[m][n])
		return memo[m][n];

	int result;

	if (m == 0 && n == 0)
		result = 1;
	else if (m == 0)
		result = uniquePaths_memoized(m, n - 1, memo);
	else if (n == 0)
		result = uniquePaths_memoized(m - 1, n, memo);
	else
		result = uniquePaths_memoized(m, n - 1, memo) + uniquePaths_memoized(m - 1, n, memo);

	memo[m][n] = result;
	return result;
}

int uniquePaths(int m, int n) {
	std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
	return uniquePaths_memoized(m - 1, n - 1, memo);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int m, n;

	// Caso de prueba 1:
	// Entrada:
	// m = 3, n = 7
	// Salida:
	// 28
	//
	m = 3, n = 7;
	std::cout << uniquePaths(m, n) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// m = 3, n = 2
	// Salida:
	// 3
	//
	m = 3, n = 2;
	std::cout << uniquePaths(m, n) << "\n";

	// Caso de prueba 3:
	// Entrada:
	// m = 7, n = 3
	// Salida:
	// 28
	//
	m = 7, n = 3;
	std::cout << uniquePaths(m, n) << "\n";

	// Caso de prueba 4:
	// Entrada:
	// m = 3, n = 3
	// Salida:
	// 6
	//
	m = 3, n = 3;
	std::cout << uniquePaths(m, n) << "\n";

	return 0;
}
