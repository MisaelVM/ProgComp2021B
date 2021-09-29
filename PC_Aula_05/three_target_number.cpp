#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

std::pair<int, int> find_2_numbers(std::vector<int>& nums, int k, int i = 0) {
	int j = nums.size() - 1;
	while (j > i) {
		int sum = nums[i] + nums[j];
		if (sum == k)
			return std::pair<int, int>(i, j);
		else if (sum > k)
			--j;
		else
			++i;
	}
	return std::pair<int, int>(-1, 0);
}

std::tuple<int, int, int> find_3_numbers(std::vector<int>& nums, int k) {
	for (int i = 0; i < (int)nums.size(); ++i) {
		std::pair<int, int> indexes = find_2_numbers(nums, k - nums[i], i + 1);
		if (indexes.first != -1)
			return std::tuple<int, int, int>(i, indexes.first, indexes.second);
	}
	return std::tuple<int, int, int>(-1, -1, 0);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> nums = { 1, 2, 4, 5, 12 };
	int k = 19;
	std::tuple<int, int, int> pos = find_3_numbers(nums, k);
	std::cout << std::get<0>(pos) << " " << std::get<1>(pos) << " " << std::get<2>(pos) << "\n";

	return 0;
}
