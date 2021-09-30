#include <iostream>
#include <vector>

std::vector<int> prefix_sum(std::vector<int>& v) {
	std::vector<int> prefix;
	prefix.reserve((int)v.size() + 1);
	prefix.push_back(0);
	for (auto& i : v)
		prefix.push_back(prefix.back() + i);
	return prefix;
}

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
	std::vector<int> max; max.reserve((int)nums.size() - k + 1);
	int max_value;
	for (int i = 0; i < (int)nums.size() - k + 1; ++i) {
		max_value = nums[i];
		for (int j = i + 1; j < i + k; ++j)
			if (nums[j] > max_value)
				max_value = nums[j];
		max.push_back(max_value);
	}
	return max;
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

	std::vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
	int k = 3;
	print_vector(maxSlidingWindow(nums, k));
	return 0;
}
