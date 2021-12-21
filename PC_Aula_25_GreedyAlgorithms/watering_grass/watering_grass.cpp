#include <bits/stdc++.h>

template <typename PriorityQueue>
void clear_pqueue(PriorityQueue& sprinklers) {
	while (!sprinklers.empty())
		sprinklers.pop();
}

template <typename PriorityQueue>
int water_grass(PriorityQueue& sprinklers, int n, double l, double w) {
	int min_sprinklers = 0;
	double grass_covered = 0.;

	while (grass_covered < l) {
		if (sprinklers.empty())
			return -1;

		double max_area_watered = -1.;
		double max_grass_watered = -1.;

		while (!sprinklers.empty()) {
			const auto& sprinkler = sprinklers.top();
			if (sprinkler.first <= grass_covered) {
				if (sprinkler.second - grass_covered > max_area_watered) {
					max_area_watered = sprinkler.second - grass_covered;
					max_grass_watered = sprinkler.second;
				}
				sprinklers.pop();
			}
			else
				break;
		}

		if (max_area_watered == -1.)
			return -1;

		++min_sprinklers;
		grass_covered = max_grass_watered;
	}

	return min_sprinklers;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, l;
	double w, x, r;

	auto cmp = [](std::pair<double, double> left, std::pair<double, double> right) { return left.first > right.first; };
	std::priority_queue<std::pair<double, double>, std::vector<std::pair<double, double>>, decltype(cmp)> sprinklers(cmp);

	while (std::cin >> n >> l >> w) {
		for (int i = 0; i < n; ++i) {
			std::cin >> x >> r;
			if (r > w / 2) {
				double s = std::sqrt(r * r - w * w / 4);
				sprinklers.push({ x - s, x + s });
			}
		}
		std::cout << water_grass(sprinklers, n, l, w) << "\n";
		clear_pqueue(sprinklers);
	}

	return 0;
}
