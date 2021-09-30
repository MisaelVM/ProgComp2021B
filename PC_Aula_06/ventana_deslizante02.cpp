#include <iostream>
#include <vector>

int smallest_contiguous_subarray_geq(std::vector<int>& nums, int S) {
	int i = -1, j, min_size = (int)nums.size() + 1, cum_sum = 0;
	for (j = 0; j < (int)nums.size(); ++j) {
		cum_sum += nums[j];
		if (cum_sum >= S) {
			cum_sum = 0;
			i = j;
			if (j - i < min_size)
				min_size = j - i;
		}
	}
	return min_size;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> nums = { 1, 2, 3, 4, 5 };
	int S = 5;
	std::cout << smallest_contiguous_subarray_geq(nums, S) << "\n";

	return 0;
}
