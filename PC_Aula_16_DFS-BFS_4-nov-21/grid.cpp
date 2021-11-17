#include <bits/stdc++.h>

int minimum_moves(std::vector<std::vector<int>>& grid) {
	std::vector<std::vector<bool>> visited(grid.size());
	for (int i = 0; i < grid.size(); ++i)
		visited[i].resize(grid[0].size(), false);

	std::pair<int, int> goal = { grid.size() - 1, grid[0].size() - 1 };
	visited[0][0] = true;

	std::queue<std::pair<int, int>> search;
	search.push({ 0, 0 });

	std::vector<int> dr = { -1, 0, 1, 0 };
	std::vector<int> dc = { 0, 1, 0, -1 };

	int moves = 0;
	int nodes_in_current_depth = 1;
	int nodes_in_next_depth = 0;

	while (!search.empty() && search.front() != goal) {
		auto curr = search.front(); search.pop();
		int r = curr.first;
		int c = curr.second;
		int jump_size = grid[r][c];
		for (int i = 0; i < 4; ++i) {
			if ((0 <= r + dr[i] * jump_size) && (r + dr[i] * jump_size < grid.size()) &&
				(0 <= c + dc[i] * jump_size) && (c + dc[i] * jump_size < grid[0].size()) &&
				(!visited[r + dr[i] * jump_size][c + dc[i] * jump_size])) {
				visited[r + dr[i] * jump_size][c + dc[i] * jump_size] = true;
				search.push({ r + dr[i] * jump_size, c + dc[i] * jump_size });
				++nodes_in_next_depth;
			}
		}
		--nodes_in_current_depth;
		if (!nodes_in_current_depth) {
			nodes_in_current_depth = nodes_in_next_depth;
			nodes_in_next_depth = 0;
			++moves;
		}
	}

	if (visited[goal.first][goal.second])
		return moves;
	return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> grid;
	int n, m;
	std::cin >> n >> m;

	grid.resize(n);
	for (int i = 0; i < n; ++i) {
		std::cin.get();
		grid.reserve(m);
		for (int j = 0; j < m; ++j)
			grid[i].push_back(std::cin.get() - '0');
	}

	std::cout << minimum_moves(grid) << "\n";

	return 0;
}
