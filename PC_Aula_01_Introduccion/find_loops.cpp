#include <iostream>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <vector>

int find_element(std::vector<int> arr, int p, int n) {
	for (int i = p; i < arr.size(); ++i)
		if (arr[i] == n)
			return i;
	return -1;
}

bool check_loop(std::vector<int> arr, int p, int q) {
	for (int i = 0; i < q - p; ++i)
		if (arr[p + i] != arr[q + i])
			return false;
	return true;
}

std::pair<int, int> find_loop(std::vector<int> arr) {
	int i = 0, j = 0;
	while (i < (int)arr.size()) {
		// Find next occurrence of the current element, if exists
		j = find_element(arr, i + 1, arr[i]);

		// If such occurrence exists, determine whether a loop exists between these occurrences or not
		if (j != -1 && check_loop(arr, i, j))
			return std::make_pair(i, j);
		++i;
	}
	return std::make_pair(0, 0);
}

void print_loop(std::vector<int> arr, std::pair<int, int> loop) {
	for (int i = loop.first; i < loop.second; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

	char input[100];
	std::vector<int> numbers;

	std::cin >> input;
	while (strcmp(input, "...")) {
		numbers.push_back(atoi(input));
		std::cin >> input;
	}

	std::pair<int, int> loop = find_loop(numbers);
	print_loop(numbers, loop);

	return 0;
}
