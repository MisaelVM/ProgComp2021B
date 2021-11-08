#include <iostream>
#include <vector>

void flood_fill(std::vector<std::vector<char>>& grid, int i, int j) {
	if (grid[i][j] == 'W')
		return;

	grid[i][j] = 'W';

	if (i > 0)
		flood_fill(grid, i - 1, j);
	if (i < grid.size() - 1)
		flood_fill(grid, i + 1, j);
	if (j > 0)
		flood_fill(grid, i, j - 1);
	if (j < grid[0].size() - 1)
		flood_fill(grid, i, j + 1);
}

int islands(std::vector<std::vector<char>>& grid) {
	int min_islands = 0;

	for (int i = 0; i < grid.size(); ++i)
		for (int j = 0; j < grid[0].size(); ++j)
			if (grid[i][j] == 'L') {
				flood_fill(grid, i, j);
				++min_islands;
			}

	return min_islands;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<char>> G;
	int r, c;
	char surface;
	
	std::cin >> r >> c;
	G.resize(r);
	for (int i = 0; i < r; ++i) {
		G[i].reserve(c);
		for (int j = 0; j < c; ++j) {
			std::cin >> surface;
			G[i].push_back(surface);
		}
	}

	std::cout << islands(G) << "\n";

	return 0;
}
