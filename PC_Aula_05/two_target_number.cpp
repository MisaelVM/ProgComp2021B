#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> find_numbers(std::vector<int>& nums, int k) {
	int i = 0, j = nums.size() - 1;
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

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> nums = { 1, 2, 7, 9, 11, 15 };
	int k = 11;
	std::pair<int, int> pos = find_numbers(nums, k);
	std::cout << pos.first << " " << pos.second << "\n";

	return 0;
}
