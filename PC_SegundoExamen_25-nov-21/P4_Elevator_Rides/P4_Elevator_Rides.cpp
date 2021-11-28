#include <bits/stdc++.h>

int ride_elevator(int n, int x, std::vector<int>& w) {
	int rides = 0;

	std::sort(w.begin(), w.end(), std::greater<int>());

	std::vector<int> RE(n);

	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < rides; ++j)
			if (RE[j] >= w[i]) {
				RE[j] = RE[j] - w[i];
				break;
			}

		if (j == rides) {
			RE[rides] = x - w[i];
			++rides;
		}
	}

	return rides;	
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
