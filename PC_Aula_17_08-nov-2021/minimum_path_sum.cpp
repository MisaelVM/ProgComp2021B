#include <bits/stdc++.h>

int minPathSum_memoized(std::vector<std::vector<int>>& grid, int m, int n, std::vector<std::vector<int>>& memo) {
	if (memo[m][n] != -1)
		return memo[m][n];

	int result;
	if (!m && !n)
		result = grid[m][n];
	else if (!m)
		result = grid[m][n] + minPathSum_memoized(grid, m, n - 1, memo);
	else if (!n)
		result = grid[m][n] + minPathSum_memoized(grid, m - 1, n, memo);
	else {
		int tmp1 = grid[m][n] + minPathSum_memoized(grid, m, n - 1, memo);
		int tmp2 = grid[m][n] + minPathSum_memoized(grid, m - 1, n, memo);
		result = std::min(tmp1, tmp2);
	}

	memo[m][n] = result;
	return result;
}

int minPathSum(std::vector<std::vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));
	return minPathSum_memoized(grid, m - 1, n - 1, memo);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> grid;

	// Caso de prueba 1:
	// Entrada:
	// grid = [[1,3,1],[1,5,1],[4,2,1]]
	// Salida:
	// 7
	//
	grid = {
		{ 1, 3, 1 },
		{ 1, 5, 1 },
		{ 4, 2, 1 }
	};
	std::cout << minPathSum(grid) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// grid = [[1,2,3],[4,5,6]]
	// Salida:
	// 12
	//
	grid = {
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};
	std::cout << minPathSum(grid) << "\n";

	return 0;
}
