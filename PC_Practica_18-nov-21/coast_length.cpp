#include <bits/stdc++.h>

void flood_fill(std::vector<std::vector<char>>& map, int i, int j, int& perimeter) {
	if (map[i][j] == '2')
		return;

	if (map[i][j] == '1') {
		++perimeter;
		return;
	}

	map[i][j] = '2';

	if (i > 0)
		flood_fill(map, i - 1, j, perimeter);
	if (i < map.size() - 1)
		flood_fill(map, i + 1, j, perimeter);
	if (j > 0)
		flood_fill(map, i, j - 1, perimeter);
	if (j < map[0].size() - 1)
		flood_fill(map, i, j + 1, perimeter);
}

int coast_length(std::vector<std::vector<char>>& map) {
	int perimeter = 0;

	for (int i = 0; i < map.size(); ++i) {
		flood_fill(map, i, 0, perimeter);
		flood_fill(map, i, map[0].size() - 1, perimeter);
	}
	
	for (int j = 0; j < map[0].size(); ++j) {
		flood_fill(map, 0, j, perimeter);
		flood_fill(map, map.size() - 1, j, perimeter);
	}

	return perimeter;
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
		map.reserve(m);
		for (int j = 0; j < m; ++j)
			map[i].push_back(std::cin.get());
	}

	std::cout << coast_length(map) << "\n";

	return 0;
}
