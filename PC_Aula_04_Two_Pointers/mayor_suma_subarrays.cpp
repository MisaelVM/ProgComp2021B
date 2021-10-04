#include <iostream>
#include <vector>

long mayor_suma_subarrays(std::vector<int>& nums) {
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
	// Caso de prueba
	// Entrada:
	// 1 -2 3 10 -4 7 2 -5
	// Salida:
	// 18
	//
	nums = { 1, -2, 3, 10, -4, 7, 2, -5 };
	std::cout << mayor_suma_subarrays(nums) << "\n";

	return 0;
}
