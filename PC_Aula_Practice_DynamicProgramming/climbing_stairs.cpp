#include <bits/stdc++.h>

int climbStairs_memoized(int n, std::vector<int>& memo) {
	if (memo[n])
		return memo[n];

	int result;
	if (n <= 2)
		result = n;
	else
		result = climbStairs_memoized(n - 1, memo) + climbStairs_memoized(n - 2, memo);
	
	memo[n] = result;
	return result;
}

int climbStairs(int n) {
	std::vector<int> memo(n + 1, 0);
	return climbStairs_memoized(n, memo);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;

	// Caso de prueba 1:
	// Entrada:
	// n = 2
	// Salida:
	// 2
	n = 2;
	std::cout << climbStairs(n) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// n = 3
	// Salida:
	// 3
	n = 3;
	std::cout << climbStairs(n) << "\n";

	return 0;
}
