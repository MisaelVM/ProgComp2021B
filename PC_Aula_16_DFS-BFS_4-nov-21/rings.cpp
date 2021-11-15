#include <bits/stdc++.h>

bool outer_layer(const std::vector<std::vector<char>>& grid, int r, int c) {
	if (grid[r][c] == '.')
		return false;

	if (!r || grid[r - 1][c] == '.')
		return true;
	if (r == grid.size() - 1 || grid[r + 1][c] == '.')
		return true;
	if (!c || grid[r][c - 1] == '.')
		return true;
	if (c == grid[0].size() - 1 || grid[r][c + 1] == '.')
		return true;

	return false;
}

int rings(std::vector<std::vector<char>>& grid) {
	std::queue<std::pair<int, int>> search;
	for (int i = 0; i < grid.size(); ++i)
		for (int j = 0; j < grid[0].size(); ++j)
			if (outer_layer(grid, i, j)) {
				grid[i][j] = '1';
				search.push({ i, j });
			}
	int rings_depth = 1;
	std::vector<int> dr = { -1, 0, 1, 0 };
	std::vector<int> dc = { 0, 1, 0, -1 };
	while (!search.empty()) {
		auto curr = search.front(); search.pop();
		int r = curr.first;
		int c = curr.second;
		for (int i = 0; i < 4; ++i) {
			if ((0 <= r + dr[i]) && (r + dr[i] < grid.size()) &&
				(0 <= c + dc[i]) && (c + dc[i] < grid[0].size()) &&
				(grid[r + dr[i]][c + dc[i]] == 'T')) {
				grid[r + dr[i]][c + dc[i]] = grid[r][c] + 1;
				search.push({ r + dr[i], c + dc[i] });
				rings_depth = std::max(rings_depth, (grid[r][c] + 1) - '0');
			}
		}
	}

	return rings_depth;
}

void print_grid(const std::vector<std::vector<char>>& grid, int depth) {
	for (auto& row : grid) {
		for (auto& i : row) {
			if (depth > 9)
				std::cout << '.';
			if (i <= '9')
				std::cout << '.' << i;
			else
				std::cout << i - '0';
		}
		std::cout << "\n";
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<char>> grid;
	int n, m;
	std::cin >> n >> m;
	grid.resize(n);
	for (int i = 0; i < n; ++i) {
		grid.reserve(m);
		std::cin.get();
		for (int j = 0; j < m; ++j)
			grid[i].push_back(std::cin.get());
	}

	int rings_depth = rings(grid);
	print_grid(grid, rings_depth);

	return 0;
}
