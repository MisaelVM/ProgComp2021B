#include <iostream>
#include <vector>
#include <set>

int max_difference_plants(std::vector<int>& nums, int k) {
	int max_difference = 0;
	int difference;
	std::set<std::pair<int, int>> near_plants;
	for (int i = 0; i < (int)nums.size(); ++i) {
		near_plants.insert({ nums[i], i });

		difference = near_plants.rbegin()->first - near_plants.begin()->first;
		if (difference > max_difference)
			max_difference = difference;

		if (i - k - 1 >= 0)
			near_plants.erase({ nums[i - k - 1], i - k - 1 });
	}
	return max_difference;
}

void print_vector(const std::vector<int>& v) {
	for (auto& i : v)
		std::cout << i << " ";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> max_differences;

	int T, N, K, x;
	std::cin >> T;
	max_differences.reserve(T);

	for (int t = 0; t < T; ++t) {
		std::vector<int> nums;
		std::cin >> N >> K;
		nums.reserve(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> x;
			nums.push_back(x);
		}
		max_differences.push_back(max_difference_plants(nums, K));
	}

	print_vector(max_differences);

	return 0;
}
