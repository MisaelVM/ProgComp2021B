#include <bits/stdc++.h>

int min_basic_operation(const std::string& str, int i, int j, std::vector<std::vector<int>>& memo) {
	if (i > j)
		return 0;

	if (memo[i][j] == -1) {
		memo[i][j] = 1 + min_basic_operation(str, i, j - 1, memo);
		for (int k = 0; k < j; ++k)
			if (str[k] == str[j]) {
				int tmp = min_basic_operation(str, i, k, memo) + min_basic_operation(str, k + 1, j - 1, memo);
				memo[i][j] = std::min(memo[i][j], tmp);
			}
	}

	return memo[i][j];
}

int minimum_operations(const std::string& str) {
	int n = str.size();
	std::vector<std::vector<int>> memo(n, std::vector<int>(n + 1, -1));
	return min_basic_operation(str, 0, n - 1, memo) * 2 + n;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string str;
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::getline(std::cin >> std::ws, str);
		std::cout << minimum_operations(str) << "\n";
	}

	return 0;
}