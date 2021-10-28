#include <iostream>
#include <vector>
#include <deque>

int interview(std::deque<int> nums) {
	int time = 0;

	int current_interview = 0;
	while (current_interview >= 0) {
		time += current_interview;

		if (nums.front() < nums.back()) {
			current_interview = nums.front();
			nums.pop_front();
		}
		else {
			current_interview = nums.back();
			nums.pop_back();
		}
	}

	return time;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::deque<int> nums;

	// Caso de prueba:
	// Entrada:
	// 4 -1 5 2 3
	// Salida:
	// 9
	//
	nums = { 4, -1, 5, 2, 3 };
	std::cout << interview(nums) << "\n";

	return 0;
}
