#include <bits/stdc++.h>

typedef unsigned long long ull;

constexpr ull MOD = 1000000007;

#define SUMA(A, B) ((A % MOD) + (B % MOD)) % MOD

template <typename PriorityQueue>
std::pair<int, int> pikeman(PriorityQueue pq, ull T) {
	ull problems_solved = 0;
	ull elapsed_time = 0;
	ull penalty = 0;
	while (!pq.empty()) {
		ull problem_time = pq.top(); pq.pop();
		elapsed_time += problem_time;
		if (elapsed_time <= T) {
			penalty = SUMA(penalty, elapsed_time);
			++problems_solved;
		}
		else
			break;
	}

	return { problems_solved, penalty };
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ull N, T, A, B, C, t;
	std::cin >> N >> T >> A >> B >> C >> t;

	std::priority_queue<ull, std::vector<ull>, std::greater<ull>> pq;
	pq.push(t);
	for (ull i = 1; i < N; ++i) {
		t = ((A * t + B) % C) + 1;
		pq.push(t);
	}

	auto pike = pikeman(pq, T);
	std::cout << pike.first << " " << pike.second << "\n";

	return 0;
}
