// Given the starting times of N (1≤N≤100,000) requests, each of which lasts
// 1000 milliseconds, and K (1≤K≤100,000), the maximum number of
// requests a server can handle concurrently, compute the minimum
// number of servers needed to process all requests.

#include <iostream>
#include <map>
#include <cmath>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K, t, requests = 0;
	std::cin >> N >> K;

	std::vector<int> A;
	std::map<int, int> D;

	for (int i = 0; i < N; ++i) {
		std::cin >> t;
		++D[t];
		--D[t + 1000];
	}

	A.push_back(0);
	for (auto& diff : D) {
		A.push_back(A.back() + diff.second);
		if (A.back() > requests)
			requests = A.back();
	}

	std::cout << ceil((float)requests / (float)K) << "\n";
	return 0;
}
