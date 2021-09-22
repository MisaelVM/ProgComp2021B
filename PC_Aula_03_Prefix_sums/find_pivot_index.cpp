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

int find_pivot_index(const std::vector<int>& v) {
	std::vector<int> p;
	p = prefix_sum(v);
	int index;
	for (index = 1; index < (int)p.size(); ++index) {
		if (p[index - 1] == p.back() - p[index])
			return index - 1;
	}
	return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> nums;
	// Caso de prueba 1
	// Entrada:
	// 2 3 -1 8 4
	// Salida:
	// 3
	//
	nums = { 2, 3, -1, 8, 4 };
	std::cout << find_pivot_index(nums) << "\n";

	// Caso de prueba 2
	// Entrada:
	// 1 7 3 6 5 6
	// Salida:
	// 3
	//
	nums = { 1, 7, 3, 6, 5, 6 };
	std::cout << find_pivot_index(nums) << "\n";

	return 0;
}
