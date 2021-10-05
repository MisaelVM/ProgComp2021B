#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<std::vector<int>> two_sum(std::vector<int>& nums, int k, int j = 0) {
	std::vector<std::vector<int>> tuplet;
	std::unordered_map<int, int> H;
	for (int i = j; i < (int)nums.size(); ++i) {
		if (H.find(k - nums[i]) != H.end()) {
			tuplet.push_back({ nums[H[k - nums[i]]], nums[i] });
			while (i + 1 < (int)nums.size() && nums[i] == nums[i + 1])
				++i;
		}
		H[nums[i]] = i;
	}
	return tuplet;
}

std::vector<std::vector<int>> three_sum(std::vector<int>& nums) {
	std::vector<std::vector<int>> triplets;
	std::sort(nums.begin(), nums.end());

	for (int i = 0; i < (int)nums.size() && nums[i] <= 0; ++i) {
		if (i == 0 || nums[i - 1] != nums[i]) {
			std::vector<std::vector<int>> indexes = two_sum(nums, -nums[i], i + 1);
			for (auto& tup : indexes)
				triplets.push_back({ nums[i], tup[0], tup[1] });
		}
	}
	
	return triplets;
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
	// -1 0 1 2 -1 -4
	// Salida:
	// -1 -1 2
	// -1 0 1
	//
	std::vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	//print_vector(three_sum(nums));
	std::vector<std::vector<int>> triplets = three_sum(nums);
	for (auto& i : triplets)
		print_vector(i);

	return 0;
}
