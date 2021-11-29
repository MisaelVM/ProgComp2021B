#include <bits/stdc++.h>

int ride_elevator(int n, int x, std::vector<int>& w) {
	std::vector<std::pair<int, int>> RE(1 << n);
	RE[0] = { 1, 0 };
	for (int s = 1; s < (1 << n); ++s) {
		// Valor inicial: se necesitan n+1 viajes en ascensor
		RE[s] = { n + 1, 0 };
		for (int p = 0; p < n; ++p) {
			if (s & (1 << p)) {
				auto option = RE[s ^ (1 << p)];
				if (option.second + w[p] <= x) {
					// Agregando p a un viaje en ascensor
					option.second += w[p];
				}
				else {
					// Reservando un nuevo viaje en ascensor para p
					++option.first;
					option.second = w[p];
				}
				RE[s] = std::min(RE[s], option);
			}
		}
	}
	return RE[(1 << n) - 1].first;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, x;
	std::cin >> n >> x;
	std::vector<int> w(n);
	for (int i = 0; i < n; ++i)
		std::cin >> w[i];

	std::cout << ride_elevator(n, x, w) << "\n";

	return 0;
}
