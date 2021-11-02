#include <iostream>
#include <queue>
#include <cstring>
#include <math.h>
#include <string>

void push_back(std::deque<int>& first_half, std::deque<int>& second_half, int x) {
	second_half.push_back(x);
	if (second_half.size() > first_half.size()) {
		first_half.push_back(second_half.front());
		second_half.pop_front();
	}
}

void push_front(std::deque<int>& first_half, std::deque<int>& second_half, int x) {
	first_half.push_front(x);
	if (first_half.size() - second_half.size() > 1) {
		second_half.push_front(first_half.back());
		first_half.pop_back();
	}
}

void push_middle(std::deque<int>& first_half, std::deque<int>& second_half, int x) {
	if (first_half.size() == second_half.size())
		first_half.push_back(x);
	else
		second_half.push_front(x);
}

int get(std::deque<int>& first_half, std::deque<int>& second_half, int x) {
	int m = ceil((first_half.size() + second_half.size()) / 2.f);
	return (x < m) ? first_half[x] : second_half[x - m];
}

void print_vector(const std::vector<int>& vec) {
	for (auto& i : vec)
		std::cout << i << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::deque<int> first_half;
	std::deque<int> second_half;

	int N, x;
	std::string S;

	std::vector<int> queries;

	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> S >> x;
		if (!strcmp(S.c_str(), "push_back")) 
			push_back(first_half, second_half, x);
		else if (!strcmp(S.c_str(), "push_front"))
			push_front(first_half, second_half, x);
		else if (!strcmp(S.c_str(), "push_middle"))
			push_middle(first_half, second_half, x);
		else
			queries.push_back(get(first_half, second_half, x));
	}

	print_vector(queries);

	return 0;
}
