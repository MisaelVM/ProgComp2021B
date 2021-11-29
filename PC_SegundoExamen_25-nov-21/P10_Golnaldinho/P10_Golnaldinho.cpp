#include <bits/stdc++.h>

void updateBIT(std::vector<int>& BIT, int n, int index, int val) {
	while (index <= n) {
		BIT[index] += val;
		index += index & (-index);
	}
}

int queryBIT(std::vector<int>& BIT, int index) {
	int sum = 0;

	while (index > 0) {
		sum += BIT[index];
		index -= index & (-index);
	}
	
	return sum;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, query;
	std::cin >> N;

	std::vector<int> BIT(N + 1, 0);

	for (int i = 0; i < N; ++i) {
		std::cin >> query;
		int nextIndex = query - queryBIT(BIT, query);
		if (i)
			std::cout << " ";
		std::cout << nextIndex;
		updateBIT(BIT, N, query, 1);
	}
	std::cout << "\n";

	return 0;
}
