#include <bits/stdc++.h>

struct suffix {
	int index; // Original index
	int rank[2]; // Rank and Next pair
};

int cmp(suffix a, suffix b) {
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1]) : (a.rank[0] < b.rank[0]);
}

std::vector<int> suffix_array(const std::string& str) {
	int n = str.size();
	std::vector<suffix> suffixes(n);

	for (int i = 0; i < n; ++i) {
		suffixes[i].index = i;
		suffixes[i].rank[0] = str[i];
		suffixes[i].rank[1] = ((i + 1) < n) ? (str[i + 1]) : -1;
	}
	
	std::sort(suffixes.begin(), suffixes.end(), cmp);

	std::vector<int> ind(n);

	for (int k = 4; k < 2 * n; k *= 2) {
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;

		for (int i = 1; i < n; ++i) {
			if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}
			else {
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			ind[suffixes[i].index] = i;
		}

		for (int i = 0; i < n; ++i) {
			int nextIndex = suffixes[i].index + k / 2;
			suffixes[i].rank[1] = (nextIndex < n) ? suffixes[ind[nextIndex]].rank[0] : -1;
		}

		std::sort(suffixes.begin(), suffixes.end(), cmp);
	}

	std::vector<int> suffix_arr(n);
	for (int i = 0; i < n; ++i)
		suffix_arr[i] = suffixes[i].index;

	return suffix_arr;
}

std::vector<int> lcp_array(const std::string& str, const std::vector<int>& suffix_arr) {
	int n = suffix_arr.size();

	std::vector<int> lcp_arr(n, 0);
	std::vector<int> inv_suffix(n, 0);

	for (int i = 0; i < n; ++i)
		inv_suffix[suffix_arr[i]] = i;

	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (inv_suffix[i] == n - 1) {
			k = 0;
			continue;
		}

		int j = suffix_arr[inv_suffix[i] + 1];

		while (i + k < n && j + k < n && str[i + k] == str[j + k])
			++k;

		lcp_arr[(inv_suffix[i] + 1) % n] = k;

		if (k)
			--k;
	}

	return lcp_arr;
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

	std::string str;
	std::vector<int> SA;
	// Caso de prueba 1
	// Entrada:
	// camel
	// Salida:
	// 0 0 0 0 0
	//
	str = "camel";
	SA = suffix_array(str);
	print_vector(lcp_array(str, SA));

	// Caso de prueba 1
	// Entrada:
	// ABABBAB
	// Salida:
	// 0 2 2 0 1 3 1
	//
	str = "ABABBAB";
	SA = suffix_array(str);
	print_vector(lcp_array(str, SA));

	return 0;
}