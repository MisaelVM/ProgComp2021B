//#include <bits/stdc++>
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

void print_vector(const std::vector<int>& v) {
	for (auto& i : v)
		std::cout << i << " ";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> nums, prefixes;
	
	// Caso de prueba 1
	// Entrada:
	// 4 5 0 -2 -3 1
	// Salida:
	// 0 4 9 9 7 4 5
	//
	nums = { 4, 5, 0, -2, -3, 1 };
	prefixes = prefix_sum(nums);
	print_vector(prefixes);

	// Caso de prueba 2
	// Entrada:
	// 9 2 -6 5 3 -2 8 4
	// Salida:
	// 0 9 11 5 10 13 11 19 23
	//
	nums = { 9, 2, -6, 5, 3, -2, 8, 4 };
	prefixes = prefix_sum(nums);
	print_vector(prefixes);

	return 0;
}
