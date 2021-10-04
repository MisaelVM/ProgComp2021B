#include <iostream>
#include <vector>

int smallest_contiguous_subarray_geq(std::vector<int>& nums, int S) {
	int i = 0, j = 0, min_size = (int)nums.size() + 1, cum_sum = 0;
	while (j < (int)nums.size()) {
		cum_sum += nums[j];
		if (cum_sum >= S) {
			if (j - i + 1 < min_size)
				min_size = j - i + 1;
			cum_sum -= (nums[i] + nums[j]);
			++i;
		}
		else
			++j;
	}
	return min_size;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// Caso de prueba 1
	// Entrada:
	// 2 4 2 5 1
	// 7
	// Salida:
	// 2
	//
	std::vector<int> nums = { 2, 4, 2, 5, 1 };
	int S = 7;
	std::cout << smallest_contiguous_subarray_geq(nums, S) << "\n";

	return 0;
}
