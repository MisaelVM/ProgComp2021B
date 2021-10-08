#include <iostream>
#include <vector>
#include <climits>
#include <set>

std::vector<long> prefix_sum(std::vector<long>& v) {
	std::vector<long> prefix;
	prefix.reserve((long)v.size() + 1);
	prefix.push_back(0);
	for (auto& i : v)
		prefix.push_back(prefix.back() + i);
	return prefix;
}

long maximum_subarray_sum(std::vector<long>& nums, int a, int b) {
	long max_subarray_sum = LONG_MIN;
	std::vector<long> p = prefix_sum(nums);
	std::set<std::pair<long, int>> subarray_prefsums;

	for (int i = a; i < (int)p.size(); ++i) {
		subarray_prefsums.insert({ p[i - a], i - a});

		if (p[i] - subarray_prefsums.begin()->first > max_subarray_sum)
			max_subarray_sum = p[i] - subarray_prefsums.begin()->first;

		if (i - b >= 0)
			subarray_prefsums.erase({ p[i - b], i - b });
	}

	return max_subarray_sum;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<long> nums;
	int n, a, b, x;
	std::cin >> n >> a >> b;
	nums.reserve(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		nums.push_back(x);
	}

	std::cout << maximum_subarray_sum(nums, a, b) << "\n";

	return 0;
}
