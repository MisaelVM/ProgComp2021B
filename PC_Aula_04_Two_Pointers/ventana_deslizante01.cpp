#include <iostream>
#include <vector>

int max_contiguous_subarray(std::vector<int>& nums, int k) {
	int max_subarray = 0;
	for (int i = 0; i < k; ++i)
		max_subarray += nums[i];

	int subarray = max_subarray;
	for (int i = k; i < (int)nums.size(); ++i) {
		subarray += (nums[i] - nums[i - k]);
		if (subarray > max_subarray)
			max_subarray = subarray;
	}
	return max_subarray;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> nums;
	int k;
	// Caso de prueba 1
	// Entrada:
	// 2 3 4 1 5
	// 3
	// Salida:
	// 10
	//
	nums = { 2, 3, 4, 1, 5 };
	k = 3;
	std::cout << max_contiguous_subarray(nums, k) << "\n";

	return 0;
}