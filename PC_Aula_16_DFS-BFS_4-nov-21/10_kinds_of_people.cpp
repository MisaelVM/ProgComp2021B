#include <bits/stdc++.h>

void flood_fill(std::vector<std::vector<int>>& map, int r, int c, int people) {
	if (map[r][c] != people)
		return;
	
	map[r][c] = 2;
	if (r > 0)
		flood_fill(map, r - 1, c, people);
	if (r < map.size() - 1)
		flood_fill(map, r + 1, c, people);
	if (c > 0)
		flood_fill(map, r, c - 1, people);
	if (c < map[0].size() - 1)
		flood_fill(map, r, c + 1, people);
}

std::string move(std::vector<std::vector<int>> map, int r1, int c1, int r2, int c2) {
	if (map[r1][c1] != map[r2][c2])
		return "neither";

	int is_dec = map[r1][c1];
	flood_fill(map, r1, c1, is_dec);

	if (map[r2][c2] != 2)
		return "neither";
	
	return (is_dec) ? "decimal" : "binary";
}

void print_vector(const std::vector<std::string>& vec) {
	for (auto& i : vec)
		std::cout << i << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int r, c;
	std::vector<std::vector<int>> map;
	std::cin >> r >> c;

	map.resize(r);
	for (int i = 0; i < r; ++i) {
		std::cin.get();
		map.reserve(c);
		for (int j = 0; j < c; ++j)
			map[i].push_back(std::cin.get() - '0');
	}

	int n, r1, c1, r2, c2;
	std::vector<std::string> solutions;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> r1 >> c1 >> r2 >> c2;
		solutions.push_back(move(map, r1 - 1, c1 - 1, r2 - 1, c2 - 1));
	}

	print_vector(solutions);

	return 0;
}
