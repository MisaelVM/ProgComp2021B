#include <bits/stdc++.h>

std::vector<int> count_digits_to_represent_until(int n) {
	std::vector<int> digits_to_represent(n + 1, 1);

	double k = 1.;

	for (int i = 1; i <= n; ++i) {
		k += std::log10(i);
		digits_to_represent[i] = (int)std::floor(k);
	}

	return digits_to_represent;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	const int max_range = 1e6;
	std::vector<int> digits_to_represent = count_digits_to_represent_until(max_range);

	int n;
	while (std::cin >> n)
		std::cout << digits_to_represent[n] << "\n";

	return 0;
}
