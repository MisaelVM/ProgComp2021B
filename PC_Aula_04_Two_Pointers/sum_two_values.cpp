#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> find_numbers(std::vector<int>& nums, int k) {
	int i = 0, j = nums.size() - 1;
	while (j > i) {
		int sum = nums[i] + nums[j];
		if (sum == k)
			return std::pair<int, int>(i, j);
		else if (sum > k)
			--j;
		else
			++i;
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

    std::pair<int, int> pos = find_numbers(nums, x);
    (pos.first != -1) ? std::cout << pos.first + 1 << " " << pos.second + 1 : std::cout << "IMPOSSIBLE";
    std::cout << "\n";

	return 0;
}
