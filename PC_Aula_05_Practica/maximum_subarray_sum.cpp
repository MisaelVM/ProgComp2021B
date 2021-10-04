#include <iostream>
#include <vector>

long maximum_subarray_sum(std::vector<int>& nums) {
	long max_subarray_sum = nums[0];
	long subarray_sum = nums[0];
	for (int i = 1; i < (int)nums.size(); ++i) {
		subarray_sum = (nums[i] > subarray_sum + nums[i]) ? nums[i] : subarray_sum + nums[i];
		if (subarray_sum > max_subarray_sum)
			max_subarray_sum = subarray_sum;
	}
	return max_subarray_sum;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> nums;
	int n, x;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		nums.push_back(x);
	}

	std::cout << maximum_subarray_sum(nums) << "\n";

	return 0;
}
