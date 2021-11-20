#include <bits/stdc++.h>

void flood_fill(std::vector<std::vector<int>>& grid, int i, int j) {
	if (!grid[i][j])
		return;

	grid[i][j] = 0;
	
	if (i > 0)
		flood_fill(grid, i - 1, j);
	if (i < grid.size() - 1)
		flood_fill(grid, i + 1, j);
	if (j > 0)
		flood_fill(grid, i, j - 1);
	if (j < grid[0].size() - 1)
		flood_fill(grid, i, j + 1);
}

int numEnclaves(std::vector<std::vector<int>>& grid) {
	for (int i = 0; i < grid.size(); ++i) {
		flood_fill(grid, i, 0);
		flood_fill(grid, i, grid[0].size() - 1);
	}

	for (int j = 1; j < grid[0].size() - 1; ++j) {
		flood_fill(grid, 0, j);
		flood_fill(grid, grid.size() - 1, j);
	}

	int land_cells = 0;
	for (int i = 1; i < grid.size() - 1; ++i)
		for (int j = 1; j < grid[0].size() - 1; ++j)
			if (grid[i][j])
				++land_cells;
	return land_cells;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> grid;

	// Caso de prueba 1:
	// Entrada:
	// [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
	// Salida:
	// 3
	//
	grid = {
		{ 0, 0, 0, 0 },
		{ 1, 0, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	};
	std::cout << numEnclaves(grid) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
	// Salida:
	// 0
	//
	grid = {
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	};
	std::cout << numEnclaves(grid) << "\n";

	return 0;
}
