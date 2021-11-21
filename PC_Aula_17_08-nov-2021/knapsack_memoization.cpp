#include <bits/stdc++.h>

int knapsack_memoization(int n, int C, std::vector<int> w, std::vector<int> v, std::vector<std::vector<int>>& memo) {
	if (memo[n][C] != -1)
		return memo[n][C];

	int result;
	if (!n || !C)
		result = 0;
	else if (w[n] > C)
		result = knapsack_memoization(n - 1, C, w, v, memo);
	else {
		int tmp1 = knapsack_memoization(n - 1, C, w, v, memo);
		int tmp2 = v[n] + knapsack_memoization(n - 1, C - w[n], w, v, memo);
		result = std::max(tmp1, tmp2);
	}

	memo[n][C] = result;
	return result;
}

int knapsack(int n, int C, std::vector<int> w, std::vector<int> v) {
	std::vector<std::vector<int>> memo(n + 1, std::vector<int>(C + 1, -1));
	return knapsack_memoization(n, C, w, v, memo);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, C;
	std::vector<int> w, v;

	// Caso de prueba 1:
	// Entrada:
	// n = 5
	// C = 10
	// w = [1,2,4,2,5]
	// v = [5,3,5,3,2]
	// Salida:
	// 16
	//
	n = 5;
	C = 10;
	w = { 0, 1, 2, 4, 2, 5 };
	v = { 0, 5, 3, 5, 3, 2 };
	std::cout << knapsack(n, C, w, v) << "\n";

	return 0;
}
