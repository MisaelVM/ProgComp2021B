#include <bits/stdc++.h>

int knapsack_bottomup(int n, int C, std::vector<int> w, std::vector<int> v) {
	std::vector<std::vector<int>> KS(n + 1, std::vector<int>(C + 1, 0));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= C; ++j)
			if (w[i] > j)
				KS[i][j] = KS[i - 1][j];
			else
				KS[i][j] = std::max(KS[i - 1][j], v[i] + KS[i - 1][j - w[i]]);

	return KS[n][C];
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
	std::cout << knapsack_bottomup(n, C, w, v) << "\n";

	return 0;
}
