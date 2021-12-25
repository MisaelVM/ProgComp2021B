#include <bits/stdc++.h>
#include <unordered_set>

typedef unsigned long long ull;

ull odd_man_out(const std::vector<ull>& guests) {
	std::unordered_set<ull> pair;
	for (auto& guest : guests)
		if (pair.count(guest))
			pair.erase(guest);
		else
			pair.insert(guest);
	return *pair.begin();
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ull N, G;
	std::cin >> N;

	for (ull i = 0; i < N; ++i) {
		std::cin >> G;
		std::vector<ull> guests(G);
		for (ull j = 0; j < G; ++j)
			std::cin >> guests[j];
		std::cout << "Case #" << i + 1 << ": " << odd_man_out(guests) << "\n";
	}

	return 0;
}
