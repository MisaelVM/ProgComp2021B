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
		suffixes[i].rank[0] = str[i] - 'a';
		suffixes[i].rank[1] = ((i + 1) < n) ? (str[i + 1] - 'a') : -1;
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

int lcp(const std::string& str) {
	std::vector<int> suffix_arr = suffix_array(str);
	int n = suffix_arr.size();

	std::vector<int> lcp_arr(n, 0);
	std::vector<int> inv_suffix(n, 0);

	for (int i = 0; i < n; ++i)
		inv_suffix[suffix_arr[i]] = i;

	int longest_str = 0;
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (inv_suffix[i] == n - 1) {
			k = 0;
			continue;
		}

		int j = suffix_arr[inv_suffix[i] + 1];

		while (i + k < n && j + k < n && str[i + k] == str[j + k])
			++k;

		longest_str = std::max(longest_str, k);

		if (k)
			--k;
	}

	return longest_str;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int L;
	std::string str;

	std::cin >> L >> str;
	std::cout << lcp(str) << "\n";

	return 0;
}
