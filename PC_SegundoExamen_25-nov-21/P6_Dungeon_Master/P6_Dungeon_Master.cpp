#include <bits/stdc++.h>

void escape(std::vector<std::vector<std::vector<char>>>& map) {
	int a = map.size();
	int b = map[0].size();
	int c = map[0][0].size();
	std::vector<int> starting_pos;
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
			for (int k = 0; k < c; ++k)
				if (map[i][j][k] == 'S')
					starting_pos = { i, j, k };

	map[starting_pos[0]][starting_pos[1]][starting_pos[2]] = '#';
	std::queue<std::vector<int>> search;
	search.push(starting_pos);

	std::vector<int> dl = { 1, -1, 0, 0, 0, 0 };
	std::vector<int> dr = { 0, 0, 1, -1, 0, 0 };
	std::vector<int> dc = { 0, 0, 0, 0, 1, -1 };

	int minutes = 0;
	int nodes_in_current_depth = 1;
	int nodes_in_next_depth = 0;
	bool scaped = false;

	while (!search.empty()) {
		auto curr = search.front(); search.pop();
		int l = curr[0];
		int r = curr[1];
		int c = curr[2];

		if (map[l][r][c] == 'E') {
			scaped = true;
			break;
		}

		for (int i = 0; i < 6; ++i) {
			if ((0 <= l + dl[i]) && (l + dl[i] < map.size()) &&
				(0 <= r + dr[i]) && (r + dr[i] < map[0].size()) &&
				(0 <= c + dc[i]) && (c + dc[i] < map[0][0].size()) &&
				(map[l + dl[i]][r + dr[i]][c + dc[i]] != '#')) {
				if (map[l + dl[i]][r + dr[i]][c + dc[i]] != 'E')
					map[l + dl[i]][r + dr[i]][c + dc[i]] = '#';
				search.push({ l + dl[i], r + dr[i], c + dc[i] });
				++nodes_in_next_depth;
			}
		}
		--nodes_in_current_depth;
		if (!nodes_in_current_depth) {
			nodes_in_current_depth = nodes_in_next_depth;
			nodes_in_next_depth = 0;
			++minutes;
		}
	}

	if (scaped)
		std::cout << "Escaped in " << minutes << " minute(s).\n";
	else
		std::cout << "Trapped!\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int L, R, C;
	std::cin >> L >> R >> C;

	while (L || R || C) {
		std::vector<std::vector<std::vector<char>>> map;
		map.resize(L);
		for (int i = 0; i < L; ++i) {
			map[i].resize(R);
			for (int j = 0; j < R; ++j) {
				std::cin >> std::ws;
				map[i][j].reserve(C);
				for (int k = 0; k < C; ++k)
					map[i][j].push_back(std::cin.get());
			}
		}
		escape(map);
		std::cin >> L >> R >> C;
	}

	return 0;
}
