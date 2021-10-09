#include <iostream>
#include <vector>
#include <climits>
#include <stack>

std::vector<int> nearest_smaller_vals(std::vector<int>& nums) {
	std::vector<int> nearest_smaller_pos;
	std::stack<std::pair<int, int>> nearest_smaller_visited;
	nearest_smaller_visited.push({ INT_MAX, -1 });
	for (int i = 0; i < (int)nums.size(); ++i) {
		while (!nearest_smaller_visited.empty() && nearest_smaller_visited.top().first >= nums[i])
			nearest_smaller_visited.pop();

		if (!nearest_smaller_visited.empty())
			nearest_smaller_pos.push_back(nearest_smaller_visited.top().second + 1);
		else
			nearest_smaller_pos.push_back(0);
		nearest_smaller_visited.push({ nums[i], i });
	}
	return nearest_smaller_pos;
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

	std::vector<int> nums;
	int n, x;
	std::cin >> n;
	nums.reserve(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		nums.push_back(x);
	}
	print_vector(nearest_smaller_vals(nums));

	return 0;
}
