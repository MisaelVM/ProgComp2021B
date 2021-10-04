#include <iostream>
#include <vector>
#include <utility>

void square_sort(std::vector<int>& nums) {
	std::vector<int> temp = nums;
	int i, j;
	for (i = 0; i < (int)temp.size(); ++i)
		if (temp[i] >= 0)
			break;
	j = i - 1;

	int k = 0;
	while (i < (int)nums.size() && j >= 0) {
		if (temp[i] * temp[i] <= temp[j] * temp[j]) {
			nums[k] = temp[i] * temp[i];
			++i;
		}
		else {
			nums[k] = temp[j] * temp[j];
			--j;
		}
		++k;
	}

	while (i < (int)nums.size()) {
		nums[k] = temp[i] * temp[i];
		++i;
		++k;
	}

	while (j >= 0) {
		nums[k] = temp[j] * temp[j];
		--j;
		++k;
	}
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

	// Caso de prueba
	// Entrada:
	// -4 -3 1 2 3
	// Salida:
	// 1 4 9 9 16
	//
	std::vector<int> nums = { -4, -3, 1, 2, 3 };
	square_sort(nums);
	print_vector(nums);

	return 0;
}
