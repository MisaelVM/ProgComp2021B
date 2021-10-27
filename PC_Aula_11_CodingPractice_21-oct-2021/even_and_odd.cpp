#include <iostream>
#include <vector>
#include <set>
#include <utility>

std::vector<int> even_and_odd(const std::vector<int>& nums) {
	std::vector<int> even_odds;

	std::set<int> evens;
	std::set<int, std::greater<int>> odds;

	for (auto& i : nums)
		if (i & 1)
			odds.insert(i);
		else
			evens.insert(i);
	
	for (auto& i : evens)
		even_odds.push_back(i);
	for (auto& i : odds)
		even_odds.push_back(i);

	return even_odds;
}

void print_vector(const std::vector<int>& vec) {
	for (auto& i : vec)
		std::cout << i << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> nums;
	int N, a;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> a;
		nums.push_back(a);
	}

	print_vector(even_and_odd(nums));

	return 0;
}
