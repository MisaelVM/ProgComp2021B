#include <bits/stdc++.h>

bool managed_to_escape(int r, int c, int n, int m) {
	return (!r || !c || r == n - 1 || c == m - 1);
}

void propagate_fire(std::vector<std::vector<int>>& map, std::pair<int, int> fire_pos) {
	map[fire_pos.first][fire_pos.second] = 0;
	std::queue<std::pair<int, int>> search;
	search.push(fire_pos);

	std::vector<int> dr = { 1, 0, -1, 0 };
	std::vector<int> dc = { 0, -1, 0, 1 };

	while (!search.empty()) {
		auto curr = search.front(); search.pop();
		int r = curr.first;
		int c = curr.second;

		for (int i = 0; i < 4; ++i) {
			if ((0 <= r + dr[i]) && (r + dr[i] < map.size()) &&
				(0 <= c + dc[i]) && (c + dc[i] < map[0].size()) &&
				(map[r + dr[i]][c + dc[i]] != -1)) {

				if (map[r + dr[i]][c + dc[i]] == -3)
					map[r + dr[i]][c + dc[i]] = 0;
				else if (map[r + dr[i]][c + dc[i]] >= 0 && map[r][c] + 1 >= map[r + dr[i]][c + dc[i]])
					continue;
				else
					map[r + dr[i]][c + dc[i]] = map[r][c] + 1;

				search.push({ r + dr[i], c + dc[i] });
			}
		}
	}
}

void escape(std::vector<std::vector<int>>& map, std::pair<int, int> start) {
	int n = map.size();
	int m = map[0].size();

	// Propagate fire
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (map[i][j] == -3)
				propagate_fire(map, { i, j });

	// Try to escape
	map[start.first][start.second] = -1;
	std::queue<std::pair<int, int>> search;
	search.push(start);

	std::vector<int> dr = { 1, 0, -1, 0 };
	std::vector<int> dc = { 0, -1, 0, 1 };

	int steps = 0;
	int nodes_in_current_depth = 1;
	int nodes_in_next_depth = 0;
	bool escaped = false;

	while (!search.empty()) {
		auto curr = search.front(); search.pop();
		int r = curr.first;
		int c = curr.second;

		if (managed_to_escape(r, c, n, m)) {
			escaped = true;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			if ((0 <= r + dr[i]) && (r + dr[i] < n) &&
				(0 <= c + dc[i]) && (c + dc[i] < m) &&
				(map[r + dr[i]][c + dc[i]] != -1)) {
				if (map[r + dr[i]][c + dc[i]] >= 0 && steps + 1 >= map[r + dr[i]][c + dc[i]])
					continue;
				map[r + dr[i]][c + dc[i]] = -1;
				search.push({ r + dr[i], c + dc[i] });
				++nodes_in_next_depth;
			}
		}
		--nodes_in_current_depth;
		if (!nodes_in_current_depth) {
			nodes_in_current_depth = nodes_in_next_depth;
			nodes_in_next_depth = 0;
			++steps;
		}
	}

	if (escaped)
		std::cout << steps + 1 << "\n";
	else
		std::cout << "IMPOSSIBLE\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T, w, h;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> w >> h;
		std::vector<std::vector<int>> building(h);
		std::pair<int, int> start;
		for (int i = 0; i < h; ++i) {
			std::cin.get();
			building.reserve(w);
			for (int j = 0; j < w; ++j) {
				char cell = std::cin.get();
				int int_cell;
				switch (cell) {
				case '#':
					int_cell = -1;
					break;
				case '.':
					int_cell = -2;
					break;
				case '*':
					int_cell = -3;
					break;
				case '@':
					start = { i, j };
					int_cell = -4;
					break;
				default:
					int_cell = -5;
					break;
				}
					
				building[i].push_back(int_cell);
			}
		}
		escape(building, start);
	}

	return 0;
}
