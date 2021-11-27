#include <bits/stdc++.h>

int rectangle_cutting_memoized(int a, int b, std::vector<std::vector<int>>& memo) {
	if (memo[a][b] != -1)
		return memo[a][b];

	int result;
	if (a == b)
		result = 0;
	else {
		result = INT_MAX;
		for (int i = 1; i <= a / 2; ++i)
			result = std::min(result, 1 + rectangle_cutting_memoized(a - i, b, memo) + rectangle_cutting_memoized(i, b, memo));
		for (int j = 1; j <= b / 2; ++j)
			result = std::min(result, 1 + rectangle_cutting_memoized(a, b - j, memo) + rectangle_cutting_memoized(a, j, memo));
	}

	memo[a][b] = result;
	return result;
}

int rectangle_cutting(int a, int b) {
	std::vector<std::vector<int>> memo(a + 1, std::vector<int>(b + 1, -1));
	return rectangle_cutting_memoized(a, b, memo);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int a, b;
	std::cin >> a >> b;

	std::cout << rectangle_cutting(a, b) << "\n";

	return 0;
}
