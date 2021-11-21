#include <bits/stdc++.h>

int knapsack(int n, int C, std::vector<int> w, std::vector<int> v) {
	if (!n || !C)
		return 0;

	if (w[n] > C)
		return knapsack(n - 1, C, w, v);

	int tmp1 = knapsack(n - 1, C, w, v);
	int tmp2 = v[n] + knapsack(n - 1, C - w[n], w, v);
	return std::max(tmp1, tmp2);
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
