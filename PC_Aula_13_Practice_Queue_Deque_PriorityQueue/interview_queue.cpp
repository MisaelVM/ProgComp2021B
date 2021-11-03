#include <iostream>
#include <utility>
#include <vector>
#include <deque>

std::vector<std::deque<int>> retreat_process(std::deque<int>& candidates) {
	int M = 0;

	std::vector<std::deque<int>> candidates_retreated;
	bool retreated = true;
	while (retreated) {
		retreated = false;
		std::deque<int> aux = { candidates[0] };
		candidates_retreated.push_back({});
		int back_pos = 0;
		for (int i = 1; i < (int)candidates.size(); ++i) {
			if (candidates[i] > candidates[i - 1]) {
				if (i - 1 == back_pos) {
					candidates_retreated[M].push_back(aux.back());
					aux.pop_back();
				}
				aux.push_back(candidates[i]);
				back_pos = i;
				retreated = true;
			}
			else if (candidates[i] < candidates[i - 1]) {
				candidates_retreated[M].push_back(candidates[i]);
				retreated = true;
			}
			else {
				aux.push_back(candidates[i]);
				back_pos = i;
			}
		}
		candidates = aux;
		++M;
	}
	candidates_retreated.pop_back();
	
	return candidates_retreated;
}

void print_deque(const std::deque<int>& deq) {
	for (auto& i : deq)
		std::cout << i << " ";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::deque<int> candidates;

	int N, v;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> v;
		candidates.push_back(v);
	}

	std::vector<std::deque<int>> process = retreat_process(candidates);

	std::cout << process.size() << "\n";
	for (auto& deq : process)
		print_deque(deq);
	print_deque(candidates);

	return 0;
}
