#include <iostream>
#include <vector>
#include <queue>

int findKthLargest(std::vector<int>& nums, int k) {
	std::priority_queue<int> pq;

	for (auto& element : nums)
		pq.push(element);

	for (int i = 0; i < k - 1; ++i)
		pq.pop();

	return pq.top();
}


int main()
{
	std::vector<int> nums;
	int k;

	// Caso de prueba 1:
	// Entrada:
	// 3 2 1 5 6 4
	// 2
	// Salida:
	// 5
	nums = { 3, 2, 1, 5, 6, 4 };
	k = 2;
	std::cout << findKthLargest(nums, k) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// 3 2 3 1 2 4 5 5 6
	// 4
	// Salida:
	// 4
	nums = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
	k = 4;
	std::cout << findKthLargest(nums, k) << "\n";
	
	return 0;
}
