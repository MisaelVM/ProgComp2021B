#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
 
std::pair<int, int> two_sum(std::vector<int>& nums, int k) {
	std::unordered_map<int, int> H;
	for (int i = 0; i < (int)nums.size(); ++i) {
		if (H.find(k - nums[i]) != H.end())
			return std::pair<int, int>(H[k - nums[i]], i);
		H[nums[i]] = i;
	}
	return std::pair<int, int>(-1, 0);
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
 
	std::pair<int, int> pos = two_sum(nums, x);
	(pos.first != -1) ? std::cout << pos.first + 1 << " " << pos.second + 1 : std::cout << "IMPOSSIBLE";
	std::cout << "\n";
 
	return 0;
}
