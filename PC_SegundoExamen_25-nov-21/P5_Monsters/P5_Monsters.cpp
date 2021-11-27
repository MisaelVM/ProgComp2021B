#include <bits/stdc++.h>

bool managed_to_scape(int r, int c, int n, int m) {
	return (!r || !c || r == n - 1 || c == m - 1);
}

std::pair<int, bool> bfs_monster(std::vector<std::vector<char>> map, int n, int m, std::pair<int, int>& starting_pos, std::pair<int, int>& exit_pos) {
	map[exit_pos.first][exit_pos.second] = '#';
	std::queue<std::pair<int, int>> search;
	search.push(exit_pos);

	std::vector<int> dr = { 1, 0, -1, 0 };
	std::vector<int> dc = { 0, -1, 0, 1 };

	int monster_steps = 0;
	int nodes_in_current_depth = 1;
	int nodes_in_next_depth = 0;
	bool reached = false;

	while (!search.empty()) {
		auto curr = search.front(); search.pop();
		int r = curr.first;
		int c = curr.second;

		if (map[r][c] == 'M') {
			reached = true;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			if ((0 <= r + dr[i]) && (r + dr[i] < map.size()) &&
				(0 <= c + dc[i]) && (c + dc[i] < map[0].size()) &&
				(map[r + dr[i]][c + dc[i]] != '#')) {
				if (map[r + dr[i]][c + dc[i]] != 'M')
					map[r + dr[i]][c + dc[i]] = '#';
				search.push({ r + dr[i], c + dc[i] });
				++nodes_in_next_depth;
			}
		}
		--nodes_in_current_depth;
		if (!nodes_in_current_depth) {
			nodes_in_current_depth = nodes_in_next_depth;
			nodes_in_next_depth = 0;
			++monster_steps;
		}
	}

	return { monster_steps, reached };
}

std::pair<int, bool> bfs_scape(std::vector<std::vector<char>>& map, int n, int m, std::pair<int, int>& starting_pos, std::pair<int, int>& exit_pos, std::stack<char>& path) {
	map[starting_pos.first][starting_pos.second] = ';';
	std::queue<std::pair<int, int>> search;
	search.push(starting_pos);

	std::vector<int> dr = { 1, 0, -1, 0 };
	std::vector<int> dc = { 0, -1, 0, 1 };

	int steps = 0;
	int nodes_in_current_depth = 1;
	int nodes_in_next_depth = 0;
	bool scaped = false;

	while (!search.empty()) {
		auto curr = search.front(); search.pop();
		int r = curr.first;
		int c = curr.second;

		if (managed_to_scape(r, c, n, m)) {
			exit_pos = curr;

			auto monster = bfs_monster(map, n, m, starting_pos, exit_pos);
			int monster_steps = monster.first;
			bool catched = monster.second;

			if (!catched || steps < monster_steps) {
				scaped = true;

				std::pair<int, int> backtracker = exit_pos;
				for (int i = 0; i < steps; ++i) {
					char step = map[backtracker.first][backtracker.second];
					path.push(step);
					switch (step) {
					case 'U':	++backtracker.first; break;
					case 'D':	--backtracker.first; break;
					case 'L':	++backtracker.second; break;
					case 'R':	--backtracker.second; break;
					default:	break;
					}
				}
				break;
			}

		}

		for (int i = 0; i < 4; ++i) {
			if ((0 <= r + dr[i]) && (r + dr[i] < map.size()) &&
				(0 <= c + dc[i]) && (c + dc[i] < map[0].size()) &&
				(map[r + dr[i]][c + dc[i]] == '.')) {
				if (dr[i]) {
					if (dr[i] > 0)
						map[r + dr[i]][c + dc[i]] = 'D';
					else
						map[r + dr[i]][c + dc[i]] = 'U';
				}
				else {
					if (dc[i] > 0)
						map[r + dr[i]][c + dc[i]] = 'R';
					else
						map[r + dr[i]][c + dc[i]] = 'L';
				}
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

	return { steps, scaped };
}

void escape_labyrinth(std::vector<std::vector<char>>& map) {
	int n = map.size();
	int m = map[0].size();

	std::pair<int, int> starting_pos;
	std::pair<int, int> exit_pos;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (map[i][j] == 'A')
				starting_pos = { i, j };

	std::stack<char> path;

	auto player = bfs_scape(map, n, m, starting_pos, exit_pos, path);
	int steps = player.first;
	bool scaped = player.second;

	if (!scaped)
		std::cout << "NO\n";
	else {
		std::cout << "YES\n" << steps << "\n";
		while (!path.empty()) {
			std::cout << path.top();
			path.pop();
		}
		std::cout << "\n";
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::vector<std::vector<char>> map;
	std::cin >> n >> m;

	map.resize(n);
	for (int i = 0; i < n; ++i) {
		std::cin.get();
		map[i].reserve(m);
		for (int j = 0; j < m; ++j)
			map[i].push_back(std::cin.get());
	}

	escape_labyrinth(map);

	return 0;
}
