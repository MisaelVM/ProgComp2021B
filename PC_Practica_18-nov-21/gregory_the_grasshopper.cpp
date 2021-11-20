#include <bits/stdc++.h>

int hops_till_clover(std::vector<std::vector<bool>>& grid, std::pair<int, int> source, std::pair<int, int> goal) {
	grid[source.first][source.second] = true;
	std::queue<std::pair<int, int>> search;
	search.push(source);

	std::vector<int> dr = { -2, -1, 1, 2, 2, 1, -1, -2 };
	std::vector<int> dc = { 1, 2, 2, 1, -1, -2, -2, -1 };

	int hops = 0;
	int nodes_in_current_depth = 1;
	int nodes_in_next_depth = 0;

	while (!search.empty() && search.front() != goal) {
		auto curr = search.front(); search.pop();
		int r = curr.first;
		int c = curr.second;
		for (int i = 0; i < 8; ++i) {
			if ((0 <= r + dr[i]) && (r + dr[i] < grid.size()) &&
				(0 <= c + dc[i]) && (c + dc[i] < grid[0].size()) &&
				(!grid[r + dr[i]][c + dc[i]])) {
				grid[r + dr[i]][c + dc[i]] = true;
				search.push({ r + dr[i], c + dc[i] });
				++nodes_in_next_depth;
			}
		}
		--nodes_in_current_depth;
		if (!nodes_in_current_depth) {
			nodes_in_current_depth = nodes_in_next_depth;
			nodes_in_next_depth = 0;
			++hops;
		}
	}

	if (grid[goal.first][goal.second])
		return hops;
	return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int R, C, GR, GC, LR, LC;

	while (std::cin >> R >> C >> GR >> GC >> LR >> LC) {
		std::vector<std::vector<bool>> grid(R, std::vector<bool>(C, false));
		int hops = hops_till_clover(grid, { GR - 1, GC - 1 }, { LR - 1, LC - 1 });
		(hops == -1) ? std::cout << "impossible\n" : std::cout << hops << "\n";
	}

	return 0;
}
