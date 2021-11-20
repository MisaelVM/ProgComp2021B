#include <bits/stdc++.h>

int calculateMinimumHP_memoized(std::vector<std::vector<int>>& dungeon, int i, int j, int m, int n, std::vector<std::vector<int>>& memo) {
	if (memo[i][j] != INT_MIN)
		return memo[i][j];
	
	int result;
	int health_to_be_lost;
	if (i == m - 1 && j == n - 1)
		health_to_be_lost = 0;
	else if (i == m - 1)
		health_to_be_lost = calculateMinimumHP_memoized(dungeon, i, j + 1, m, n, memo);
	else if (j == n - 1)
		health_to_be_lost = calculateMinimumHP_memoized(dungeon, i + 1, j, m, n, memo);
	else {
		int tmp1 = calculateMinimumHP_memoized(dungeon, i, j + 1, m, n, memo);
		int tmp2 = calculateMinimumHP_memoized(dungeon, i + 1, j, m, n, memo);
		health_to_be_lost = std::max(tmp1, tmp2);
	}
	result = std::min(dungeon[i][j], health_to_be_lost + dungeon[i][j]);

	memo[i][j] = result;
	return result;
}

int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
	int m = dungeon.size();
	int n = dungeon[0].size();
	std::vector<std::vector<int>> memo(m, std::vector<int>(n, INT_MIN));
	int health_to_be_lost = calculateMinimumHP_memoized(dungeon, 0, 0, m, n, memo);
	return (health_to_be_lost > 0) ? 1 : 1 - health_to_be_lost;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> dungeon;

	// Caso de prueba 1:
	// Entrada:
	// [[-2,-3,3],[-5,-10,1],[10,30,-5]]
	// Salida:
	// 7
	//
	dungeon = {
		{ -2, -3, 3 },
		{ -5, -10, 1 },
		{ 10, 30, -5 }
	};
	std::cout << calculateMinimumHP(dungeon) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// [[0]]
	// Salida:
	// 1
	//
	dungeon = {
		{ 0 }
	};
	std::cout << calculateMinimumHP(dungeon) << "\n";

	return 0;
}
