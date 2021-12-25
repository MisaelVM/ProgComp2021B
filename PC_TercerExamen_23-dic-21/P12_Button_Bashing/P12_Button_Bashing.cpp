#include <bits/stdc++.h>
#include <unordered_map>

std::pair<int, int> bash_buttons(const std::vector<int>& buttons, int goal) {
	std::unordered_map<int, bool> visited;
	visited[0] = true;
	visited[goal] = false;

	std::queue<int> search;
	search.push(0);

	int moves = 0;

	int min_extra = INT_MAX;
	int min_moves = INT_MAX;
	int nodes_in_current_depth = 1;
	int nodes_in_next_depth = 0;
	while (!search.empty()) {
		int curr = search.front(); search.pop();

		if (curr > goal && curr < min_extra) {
			min_extra = curr - goal;
			min_moves = moves;
		}
		
		if (curr == goal)
			return { moves, 0 };

		for (auto& i : buttons) {
			int neighbour = (curr + i > 3600) ? 3600 : ((curr + i < 0) ? 0 : curr + i);
			if (!visited[neighbour]) {
				visited[neighbour] = true;
				search.push(neighbour);
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

	return { min_moves, min_extra };
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int TC, n, t;
	std::cin >> TC;
	for (int i = 0; i < TC; ++i) {
		std::cin >> n >> t;
		std::vector<int> buttons(n);
		for (int j = 0; j < n; ++j)
			std::cin >> buttons[j];
		auto press = bash_buttons(buttons, t);
		std::cout << press.first << " " << press.second << "\n";
	}

	return 0;
}
