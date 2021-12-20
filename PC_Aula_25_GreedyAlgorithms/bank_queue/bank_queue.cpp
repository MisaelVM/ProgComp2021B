#include <bits/stdc++.h>

template <typename PriorityQueue>
int serve_persons(PriorityQueue q, int T) {
	std::vector<bool> served(T);

	int money = 0;
	while (!q.empty()) {
		auto p = q.top(); q.pop();
		int pos = p.second;
		while (pos >= 0) {
			if (!served[pos]) {
				served[pos] = true;
				money += p.first;
				break;
			}
			--pos;
		}
	}

	return money;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, T, c, t;
	std::cin >> N >> T;

	auto cmp = [](std::pair<int, int> left, std::pair<int, int> right) { return left.first < right.first; };
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);

	for (int i = 0; i < N; ++i) {
		std::cin >> c >> t;
		pq.push({ c, t });
	}

	std::cout << serve_persons(pq, T) << "\n";

	return 0;
}
