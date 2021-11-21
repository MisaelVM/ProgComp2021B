#include <bits/stdc++.h>

int mfps(std::vector<std::vector<int>>& grid, int i, int j, std::vector<std::vector<int>>& memo) {
	if (memo[i][j] != INT_MAX)
		return memo[i][j];

	int result;
	if (i == 0)
		result = grid[i][j];
	else {
		int minimum = INT_MAX;
		for (int k = 0; k < grid.size(); ++k) {
			if (k == j)
				continue;
			int local_sum = grid[i][j] + mfps(grid, i - 1, k, memo);
			minimum = std::min(minimum, local_sum);
		}
		result = minimum;
	}
	memo[i][j] = result;
	return result;
}

int minFallingPathSum(std::vector<std::vector<int>>& grid) {
	int n = grid.size();

	std::vector<std::vector<int>> memo(n, std::vector<int>(n, INT_MAX));
	int minimum = INT_MAX;
	for (int i = 0; i < n; ++i)
		minimum = std::min(minimum, mfps(grid, n - 1, i, memo));
	
	return minimum;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> grid;

	grid = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	std::cout << minFallingPathSum(grid) << "\n";

	grid = { { 7 } };
	std::cout << minFallingPathSum(grid) << "\n";

	return 0;
}
