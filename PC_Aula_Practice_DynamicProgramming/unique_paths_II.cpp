#include <bits/stdc++.h>

int uniquePathsWithObstacles_memoized(std::vector<std::vector<int>>& obstacleGrid, int i, int j, std::vector<std::vector<int>>& memo) {
	if (memo[i][j] != -1)
		return memo[i][j];
	
	int result;
	if (obstacleGrid[i][j])
		result = 0;
	else if (!i && !j)
		result = 1;
	else if (!i)
		result = uniquePathsWithObstacles_memoized(obstacleGrid, i, j - 1, memo);
	else if (!j)
		result = uniquePathsWithObstacles_memoized(obstacleGrid, i - 1, j, memo);
	else
		result = uniquePathsWithObstacles_memoized(obstacleGrid, i, j - 1, memo) + uniquePathsWithObstacles_memoized(obstacleGrid, i - 1, j, memo);

	memo[i][j] = result;
	return result;
}

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));
	return uniquePathsWithObstacles_memoized(obstacleGrid, m - 1, n - 1, memo);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> obstacleGrid;
	// Caso de prueba 1:
	// Entrada:
	// obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
	// Salida:
	// 2
	obstacleGrid = {
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 0 }
	};
	std::cout << uniquePathsWithObstacles(obstacleGrid) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// obstacleGrid = [[0,1],[0,0]]
	// Salida:
	// 1
	obstacleGrid = {
		{ 0, 1 },
		{ 0, 0 }
	};
	std::cout << uniquePathsWithObstacles(obstacleGrid) << "\n";

	return 0;
}
