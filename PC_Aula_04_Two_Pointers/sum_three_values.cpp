#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
 
std::pair<int, int> two_sum(std::vector<int>& nums, int k, int j = 0) {
	std::unordered_map<int, int> H;
	for (int i = j; i < (int)nums.size(); ++i) {
		if (H.find(k - nums[i]) != H.end())
			return std::pair<int, int>(H[k - nums[i]], i);
		H[nums[i]] = i;
	}
	return std::pair<int, int>(-1, 0);
}

std::tuple<int, int, int> three_sum(std::vector<int>& nums, int k) {
	for (int i = 0; i < (int)nums.size(); ++i) {
		std::pair<int, int> indexes = two_sum(nums, k - nums[i], i + 1);
		if (indexes.first != -1)
			return std::tuple<int, int, int>(i, indexes.first, indexes.second);
	}
	return std::tuple<int, int, int>(-1, -1, 0);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
 
	std::vector<int> nums;
	int n, x, v;
	std::cin >> n >> x;
	nums.reserve(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> v;
		nums.push_back(v);
	}
 
	std::tuple<int, int, int> pos = three_sum(nums, x);
	(std::get<0>(pos) != -1) ? std::cout << std::get<0>(pos) + 1 << " " << std::get<1>(pos) + 1 << " " << std::get<2>(pos) + 1 : std::cout << "IMPOSSIBLE";
	std::cout << "\n";
 
	return 0;
}
