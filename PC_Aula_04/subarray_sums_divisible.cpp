//#include <bits/stdc++>
#include <iostream>
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

int subarraysDivByK(std::vector<int>& nums, int k) {
	int count = 0;
	std::vector<int> p = prefix_sum(nums);

	std::vector<int> remainders(k, 0);
	for (auto& i : p) {
		int rem = (i % k + k) % k;
		count += remainders[rem];
		++remainders[rem];
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
	// 4 5 0 -2 -3 1
	// 5
	// Salida:
	// 7
	//
	nums = { 4, 5, 0, -2, -3, 1 };
	k = 5;
	std::cout << subarraysDivByK(nums, k) << "\n";

	// Caso de prueba 2
	// Entrada:
	// 9 2 -6 5 3 -2 8 4
	// 3
	// Salida:
	// 10
	//
	nums = { 9, 2, -6, 5, 3, -2, 8, 4 };
	k = 3;
	std::cout << subarraysDivByK(nums, k) << "\n";

	return 0;
}
