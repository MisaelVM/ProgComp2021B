#include <iostream>
#include <utility>
#include <iomanip>
#include <vector>
#include <deque>

std::vector<std::pair<int, int>> dole(int N, int k, int m) {
	std::vector<std::pair<int, int>> chosen;

	std::deque<int> deq(N);
	for (int i = 0; i < N; ++i)
		deq[i] = i + 1;

	int i = 0;
	int j = N - 1;

	int total_picked = 0;
	while (total_picked < N) {
		for (int p = 0; p < k - 1 || !deq[i]; ++p) {
			if (!deq[i])
				--p;
			i = (++i) % N;
		}

		for (int q = 0; q < m - 1 || !deq[j]; ++q) {
			if (!deq[j])
				--q;
			j = (j + N - 1) % N;
		}

		chosen.push_back({ deq[i], deq[j] });

		++total_picked;
		if (i != j)
			++total_picked;
		deq[i++] = 0; i %= N;
		deq[j--] = 0; j = (j + N) % N;
	}

	return chosen;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<std::pair<int, int>>> doles;

	int N, k, m;
	while (true) {
		std::cin >> N >> k >> m;
		if (!N && !k && !m)
			break;

		doles.push_back(dole(N, k, m));
	}

	for (auto& dole : doles) {
		for (int i = 0; i < (int)dole.size(); ++i) {
			if (i)
				std::cout << ",";
			std::cout << std::setw(3);
			std::cout << dole[i].first;
			if (dole[i].first != dole[i].second) {
				std::cout << std::setw(3);
				std::cout << dole[i].second;
			}
		}
		std::cout << "\n";
	}

	return 0;
}
