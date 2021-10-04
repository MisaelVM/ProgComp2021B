//#include <bits/stdc++>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> prefix_sum(const std::vector<int>& v) {
	std::vector<int> prefix;
	prefix.reserve((int)v.size() + 1);
	prefix.push_back(0);
	for (auto& i : v)
		prefix.push_back(prefix.back() + i);
	return prefix;
}

void print_vector(const std::vector<int>& v) {
	for (auto& i : v)
		std::cout << i << " ";
	std::cout << "\n";
}

int subarraySum(std::vector<int>& nums, int k) {
	int count = 0;
	std::vector<int> p = prefix_sum(nums);

	std::unordered_map<int, int> H;
	for (auto& i : p) {
		int diff = i - k;
		if (H.find(diff) != H.end())
			count += H[diff];
		++H[i];
	}

	return count;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> nums;
	int k;
	// Caso de prueba 1
	// Entrada:
	// 1 1 1
	// 2
	// Salida:
	// 2
	//
	nums = { 1, 1, 1 };
	k = 2;
	std::cout << subarraySum(nums, k) << "\n";

	// Caso de prueba 2
	// Entrada:
	// 1 2 3
	// 3
	// Salida:
	// 2
	//
	nums = { 1, 2, 3 };
	k = 3;
	std::cout << subarraySum(nums, k) << "\n";

	return 0;
}
