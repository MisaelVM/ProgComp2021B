#include <bits/stdc++.h>

std::string reconstruct(std::vector<std::pair<int, std::string>>& SA, int l) {
	bool reconstructible = true;
	std::string reconstructed_string(l, '\0');

	for (auto& entry : SA) {
		bool star = false;
		int p = entry.first;
		std::string suffix = entry.second;
		for (int i = p; i < l; ++i) {
			if (suffix[i - p] == '*') {
				star = true;
				break;
			}
			(reconstructed_string[i] && reconstructed_string[i] != suffix[i - p]) ?
				reconstructible = false : reconstructed_string[i] = suffix[i - p];
		}

		if (star)
			for (int i = l - 1, j = suffix.size() - 1; j >= 0 && suffix[j] != '*'; --j, --i)
				(reconstructed_string[i] && reconstructed_string[i] != suffix[j]) ?
					reconstructible = false : reconstructed_string[i] = suffix[j];
	}

	for (auto& character : reconstructed_string)
		reconstructible = reconstructible && character;

	return (reconstructible) ? reconstructed_string : "IMPOSSIBLE";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t, l, s, p;
	std::string suffix;

	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> l >> s;
		std::vector<std::pair<int, std::string>> SA(s);
		for (int j = 0; j < s; ++j) {
			std::cin >> p >> suffix;
			SA[j] = { p - 1, suffix };
		}
		std::cout << reconstruct(SA, l) << "\n";
	}

	return 0;
}
