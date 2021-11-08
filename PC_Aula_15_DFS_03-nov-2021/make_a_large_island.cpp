#include <iostream>
#include <vector>
#include <set>

int floodFill(std::vector<std::vector<int>>& grid, int i, int j, int mark) {
	if (grid[i][j] != 1)
		return 0;

	grid[i][j] = mark;
	int area = 1;

	if (i > 0)
		area += floodFill(grid, i - 1, j, mark);
	if (i < grid.size() - 1)
		area += floodFill(grid, i + 1, j, mark);
	if (j > 0)
		area += floodFill(grid, i, j - 1, mark);
	if (j < grid.size() - 1)
		area += floodFill(grid, i, j + 1, mark);

	return area;
}

std::set<int> get_neighbouring_islands(const std::vector<std::vector<int>>& grid, int i, int j) {
	std::set<int> neighbouring_islands;

	if (i > 0 && grid[i - 1][j])
		neighbouring_islands.insert(grid[i - 1][j]);
	if (i < grid.size() - 1 && grid[i + 1][j])
		neighbouring_islands.insert(grid[i + 1][j]);
	if (j > 0 && grid[i][j - 1])
		neighbouring_islands.insert(grid[i][j - 1]);
	if (j < grid[0].size() - 1 && grid[i][j + 1])
		neighbouring_islands.insert(grid[i][j + 1]);

	return neighbouring_islands;
}

int largestIsland(std::vector<std::vector<int>>& grid) {
	int max_area = 0;
	std::vector<int> islands_areas;
	int island_count = 0;
	for (int i = 0; i < grid.size(); ++i)
		for (int j = 0; j < grid[0].size(); ++j)
			if (grid[i][j] == 1) {
				int area = floodFill(grid, i, j, island_count + 2);
				islands_areas.push_back(area);
				max_area = std::max(max_area, area);
				++island_count;
			}

	for (int i = 0; i < grid.size(); ++i)
		for (int j = 0; j < grid[0].size(); ++j)
			if (!grid[i][j]) {
				std::set<int> neighbouring_islands = get_neighbouring_islands(grid, i, j);
				int large_island_area = 1;
				for (auto& island_mark : neighbouring_islands)
					large_island_area += islands_areas[island_mark - 2];
				max_area = std::max(max_area, large_island_area);
			}

	return max_area;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> G;

	// Caso de prueba 1
	// Entrada:
	// 1 0
	// 0 1
	// Salida:
	// 3
	G = { { 1, 0 }, { 0, 1 } };
	std::cout << largestIsland(G) << "\n";

	// Caso de prueba 2
	// Entrada:
	// 1 1
	// 1 0
	// Salida:
	// 4
	G = { { 1, 1 }, { 0, 1 } };
	std::cout << largestIsland(G) << "\n";

	// Caso de prueba 3
	// Entrada:
	// 1 1
	// 1 1
	// Salida:
	// 4
	G = { { 1, 1 }, { 1, 1 } };
	std::cout << largestIsland(G) << "\n";

	return 0;
}
