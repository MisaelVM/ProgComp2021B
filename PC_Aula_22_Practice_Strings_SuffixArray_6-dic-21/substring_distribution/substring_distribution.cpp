#include <bits/stdc++.h>

typedef unsigned long long ull;

struct suffix {
	ull index; // Original index
	ull rank[2]; // Rank and Next pair
};

int cmp(suffix a, suffix b) {
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1]) : (a.rank[0] < b.rank[0]);
}

std::vector<ull> suffix_array(const std::string& str) {
	ull n = str.size();
	std::vector<suffix> suffixes(n);

	for (ull i = 0; i < n; ++i) {
		suffixes[i].index = i;
		suffixes[i].rank[0] = str[i] - 'a';
		suffixes[i].rank[1] = ((i + 1) < n) ? (str[i + 1] - 'a') : -1;
	}
	
	std::sort(suffixes.begin(), suffixes.end(), cmp);

	std::vector<ull> ind(n);

	for (ull k = 4; k < 2 * n; k *= 2) {
		ull rank = 0;
		ull prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;

		for (ull i = 1; i < n; ++i) {
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

		for (ull i = 0; i < n; ++i) {
			ull nextIndex = suffixes[i].index + k / 2;
			suffixes[i].rank[1] = (nextIndex < n) ? suffixes[ind[nextIndex]].rank[0] : -1;
		}

		std::sort(suffixes.begin(), suffixes.end(), cmp);
	}

	std::vector<ull> suffix_arr(n);
	for (ull i = 0; i < n; ++i)
		suffix_arr[i] = suffixes[i].index;

	return suffix_arr;
}

std::vector<ull> lcp_array(const std::string& str, const std::vector<ull>& suffix_arr) {
	ull n = suffix_arr.size();

	std::vector<ull> lcp_arr(n, 0);
	std::vector<ull> inv_suffix(n, 0);

	for (ull i = 0; i < n; ++i)
		inv_suffix[suffix_arr[i]] = i;

	ull k = 0;
	for (ull i = 0; i < n; ++i) {
		if (inv_suffix[i] == n - 1) {
			k = 0;
			continue;
		}

		ull j = suffix_arr[inv_suffix[i] + 1];

		while (i + k < n && j + k < n && str[i + k] == str[j + k])
			++k;

		lcp_arr[inv_suffix[i]] = k;

		if (k)
			--k;
	}

	return lcp_arr;
}

std::vector<ull> substr_dist(std::string& str) {
	ull n = str.size();
	std::vector<ull> SA = suffix_array(str);
	std::vector<ull> LCP = lcp_array(str, SA);
	std::vector<ull> PRE(n + 1, 0);

	for (ull i = 0; i < n; ++i) {
		++PRE[LCP[i]];
		--PRE[n - SA[i]];
	}

	std::vector<ull> substrs(n, 0);
	substrs[0] = PRE[0];
	for (int i = 1; i < n; ++i)
		substrs[i] = PRE[i] + substrs[i - 1];
	
	return substrs;
}

void print_vector(const std::vector<ull>& vec) {
	for (auto& i : vec)
		std::cout << i << " ";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string str;
	std::cin >> str;
	print_vector(substr_dist(str));	

	return 0;
}
