#include <iostream>
#include <deque>
#include <vector>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
	std::vector<int> max; max.reserve((int)nums.size() - k + 1);
	std::deque<int> dque;
	for (int i = 0; i < k; ++i) {
		while (!dque.empty() && nums[i] >= nums[dque.back()])
			dque.pop_back();
		dque.push_back(i);
	}
	max.push_back(nums[dque.front()]);

	for (int i = k; i < (int)nums.size(); ++i) {
		while (!dque.empty() && i - k >= dque.front())
			dque.pop_front();
		while (!dque.empty() && nums[i] >= nums[dque.back()])
			dque.pop_back();
		dque.push_back(i);
		max.push_back(nums[dque.front()]);
	}

	return max;
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
	int k;
	// Caso de prueba 1
	// Entrada:
	// 1 3 -1 -3 5 3 6 7
	// 3
	// Salida:
	// 3 3 5 6 7
	//
	nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
	k = 3;
	print_vector(maxSlidingWindow(nums, k));

	// Caso de prueba 2
	// Entrada:
	// 9 11
	// 2
	// Salida:
	// 11
	//
	nums = { 9, 11 };
	k = 2;
	print_vector(maxSlidingWindow(nums, k));

	// Caso de prueba 3
	// Entrada:
	// 1 -1
	// 1
	// Salida:
	// 1 -1
	//
	nums = { 1, -1 };
	k = 1;
	print_vector(maxSlidingWindow(nums, k));

	return 0;
}
