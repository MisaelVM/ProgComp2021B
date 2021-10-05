#include <iostream>
#include <vector>
#include <set>

std::vector<long> sliding_cost(std::vector<long>& nums, long k) {
	std::vector<long> cost; cost.reserve((long)nums.size() - k + 1);
	long upper_half_cost = 0;
	long lower_half_cost = 0;
	std::set<std::pair<long, long>> upper_half;
	std::set<std::pair<long, long>> lower_half;

	for (long i = 0; i < k; ++i) {
		lower_half.insert({nums[i], i});
		lower_half_cost += nums[i];
	}
	while (lower_half.size() - upper_half.size() > k % 2) {
		auto element = lower_half.rbegin();
		upper_half.insert(*element);
		upper_half_cost += element->first;
		lower_half_cost -= element->first;
		lower_half.erase(*element);
	}
	cost.push_back(upper_half_cost - lower_half_cost + lower_half.rbegin()->first * (k % 2));

	for (long i = k; i < (long)nums.size(); ++i) {
		if (lower_half.find({nums[i - k], i - k}) != lower_half.end()) {
			lower_half.erase({nums[i - k], i - k});
			lower_half_cost -= nums[i - k];
		}
		else {
			upper_half.erase({nums[i - k], i - k});
			upper_half_cost -= nums[i - k];
		}

		if (lower_half.empty() || nums[i] > lower_half.rbegin()->first) {
			upper_half.insert({nums[i], i});
			upper_half_cost += nums[i];
		}
		else {
			lower_half.insert({nums[i], i});
			lower_half_cost += nums[i];
		}

		while (lower_half.size() - upper_half.size() > k % 2) {
			if (lower_half.size() > upper_half.size()) {
				auto element = lower_half.rbegin();
				upper_half.insert(*element);
				upper_half_cost += element->first;
				lower_half_cost -= element->first;
				lower_half.erase(*element);
			}
			else {
				auto element = upper_half.begin();
				lower_half.insert(*element);
				lower_half_cost += element->first;
				upper_half_cost -= element->first;
				upper_half.erase(*element);
			}
		}
		cost.push_back(upper_half_cost - lower_half_cost + lower_half.rbegin()->first * (k % 2));
	}

	return cost;
}

void print_vector(const std::vector<long>& v) {
	for (auto& i : v)
		std::cout << i << " ";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k, v;
	std::vector<long> nums;
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> v;
		nums.push_back(v);
	}

	print_vector(sliding_cost(nums, k));

	return 0;
}
