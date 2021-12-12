#include <bits/stdc++.h>

std::vector<int> KMP_array(const std::string& P) {
	int m = P.size();

	std::vector<int> F(m, 0);

	int i = 1, j = 0;
	while (i < m) {
		if (P[i] == P[j]) {
			F[i] = j + 1;
			++i;
			++j;
		}
		else if (j > 0)
			j = F[j - 1];
		else {
			F[i] = 0;
			++i;
		}
	}

	return F;
}

std::vector<int> KMP(const std::string& T, const std::string& P) {
	int n = T.size();
	int m = P.size();

	std::vector<int> F = KMP_array(P);

	std::vector<int> ocurrences;

	int i = 0, j = 0;

	while (i < n) {
		if (P[j] == T[i]) {
			if (j == m - 1)
				ocurrences.push_back(i - m + 1);
			++i;
			++j;
		}
		else if (j > 0)
			j = F[j - 1];
		else
			++i;
	}

	return ocurrences;
}

void print_vector(const std::vector<int>& vec) {
	for (auto& i : vec)
		std::cout << i << " ";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string pattern, text;

	while (std::getline(std::cin >> std::ws, pattern)) {
		std::getline(std::cin >> std::ws, text);
		print_vector(KMP(text, pattern));
	}

	return 0;
}
