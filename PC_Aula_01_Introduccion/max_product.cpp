#include <iostream>
#include <vector>

int max_product(std::vector<int> vec) {
	int i = 2;
	int p; // First largest number index
	int q; // Second largest number index

	// Initialising first and second largest numbers indexes
	(vec[0] > vec[1]) ? p = 0, q = 1 : p = 1, q = 0;

	while (i < (int)vec.size()) {
		if (vec[i] > vec[p]) {
			// Updates both indexes
			q = p;
			p = i;
		}
		else if (vec[i] > vec[q]) {
			// Only second largest number index must be updated
			q = i;
		}
		++i;
	}

	// Product between the two largest numbers (Maximum Product)
	return vec[p] * vec[q];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n;
	std::vector<int> numbers;

	std::cin >> n;
	numbers.reserve(n);

	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		numbers.push_back(x);
	}

	std::cout << max_product(numbers) << "\n";

	return 0;
}