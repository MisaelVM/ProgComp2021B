#include <iostream>
#include <vector>
#include <set>
#include <utility>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> population_height;
	int NC, N, h;
	std::cin >> NC;
	population_height.resize(NC);
	for (int i = 0; i < NC; ++i) {
		std::cin >> N;
		std::set<std::pair<int, int>> popul;
		for (int j = 0; j < N; ++j) {
			std::cin >> h;
			popul.insert({ h, j });
		}
		for (auto& height : popul)
			population_height[i].push_back(height.first);
	}

	for (auto& citizens : population_height) {
		for (auto& i : citizens)
			std::cout << i << " ";
		std::cout << "\n";
	}

	return 0;
}
