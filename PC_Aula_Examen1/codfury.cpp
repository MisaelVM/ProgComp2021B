#include <iostream>
#include <utility>
#include <climits>
#include <vector>

std::pair<int, int> megatron_rage(std::vector<int>& nums, int M) {
	int max_planets = 0;
	int autobots = 0;
	int min_autobots = INT_MAX;

	int i = 0, j = 0;
	while (j < (int)nums.size()) {
		autobots += nums[j];

		while (autobots > M) {
			autobots -= nums[i];
			++i;
		}
		
		int planets = j - i + 1;
		if ((planets > max_planets) || (max_planets == planets && min_autobots > autobots)) {
			max_planets = planets;
			min_autobots = autobots;
		}

		++j;
	}

	return { min_autobots, max_planets };
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::pair<int, int>> rages;

	int T, P, M, x;
	std::cin >> T;
	rages.reserve(T);

	for (int t = 0; t < T; ++t) {
		std::vector<int> nums;
		std::cin >> P >> M;
		nums.reserve(P);
		for (int i = 0; i < P; ++i) {
			std::cin >> x;
			nums.push_back(x);
		}
		rages.push_back(megatron_rage(nums, M));
	}

	for (auto& i : rages)
		std::cout << i.first << " " << i.second << "\n";

	return 0;
}
