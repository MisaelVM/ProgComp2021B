#include <iostream>
#include <vector>

std::vector<long> prefix_sum(std::vector<long>& v) {
	std::vector<long> prefix;
	prefix.reserve((long)v.size() + 1);
	prefix.push_back(0);
	for (auto& i : v)
		prefix.push_back(prefix.back() + i);
	return prefix;
}

void update(std::vector<long>& nums, std::vector<long>& prefixes, long k, long u) {
	nums[k - 1] = u;
	for (long i = k; i < (long)prefixes.size(); ++i)
		prefixes[i] = (prefixes[i - 1] + nums[i - 1]);
}

long max_pref_sum(std::vector<long>& prefixes, long a, long b) {
	long max = 0;
	for (long i = a; i <= b; ++i)
		if (prefixes[i] - prefixes[a - 1] > max)
			max = prefixes[i] - prefixes[a - 1];
	return max;
}

void print_vector(const std::vector<long>& v) {
	for (auto& i : v)
		std::cout << i << "\n";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<long> nums;
	long n, q, v;
	std::cin >> n >> q;
	nums.reserve(n);
	for (long i = 0; i < n; ++i) {
		std::cin >> v;
		nums.push_back(v);
	}
	std::vector<long> p = prefix_sum(nums);

	std::vector<long> queries;
	long query, a, b;
	for (long i = 0; i < q; ++i) {
		std::cin >> query >> a >> b;
		if (query == 1)
			update(nums, p, a, b);
		if (query == 2)
			queries.push_back(max_pref_sum(p, a, b));
	}

	print_vector(queries);

	return 0;
}
