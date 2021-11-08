#include <iostream>
#include <vector>

int dfs(std::vector<std::vector<int>>& grid, int i, int j) {
	if (!grid[i][j])
		return 0;

	grid[i][j] = 0;
	int area = 1;

	if (i > 0)
		area += dfs(grid, i - 1, j);

	if (i < grid.size() - 1)
		area += dfs(grid, i + 1, j);

	if (j > 0)
		area += dfs(grid, i, j - 1);

	if (j < grid[0].size() - 1)
		area += dfs(grid, i, j + 1);

	return area;
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	int ans = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (grid[i][j])
				ans = std::max(ans, dfs(grid, i, j));
	return ans;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> G;

	// Caso de prueba
	// Entrada:
	// 0 0 1 0 0 0 0 1 0 0 0 0 0
	// 0 0 0 0 0 0 0 1 1 1 0 0 0
	// 0 1 1 0 1 0 0 0 0 0 0 0 0
	// 0 1 0 0 1 1 0 0 1 0 1 0 0
	// 0 1 0 0 1 1 0 0 1 1 1 0 0
	// 0 0 0 0 0 0 0 0 0 0 1 0 0
	// 0 0 0 0 0 0 0 1 1 1 0 0 0
	// 0 0 0 0 0 0 0 1 1 0 0 0 0
	// Salida:
	// 6
	G =	{
			{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 
			{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
			{ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 },
			{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 }
		};
	std::cout << maxAreaOfIsland(G) << "\n";

	return 0;
}
