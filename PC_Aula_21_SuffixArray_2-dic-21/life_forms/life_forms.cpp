#include <bits/stdc++.h>

struct suffix {
	int index; // Original index
	int rank[2]; // Rank and Next pair
	int color;
};

int cmp(suffix a, suffix b) {
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1]) : (a.rank[0] < b.rank[0]);
}

std::vector<std::pair<int, int>> suffix_array(const std::string& str) {
	int n = str.size();
	std::vector<suffix> suffixes(n);

	int color = 0;
	for (int i = 0; i < n; ++i) {
		suffixes[i].index = i;
		suffixes[i].rank[0] = str[i] - 'A';
		suffixes[i].rank[1] = ((i + 1) < n) ? (str[i + 1] - 'A') : -1;
		suffixes[i].color = color;
		if (str[i] < 101)
			++color;
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

	std::vector<std::pair<int, int>> suffix_arr(n);
	for (int i = 0; i < n; ++i)
		suffix_arr[i] = { suffixes[i].index, suffixes[i].color };

	return suffix_arr;
}

std::vector<std::pair<int, int>> lcp_array(const std::string& str, int n, const std::vector<std::pair<int, int>>& suffix_arr) {
	int m = suffix_arr.size();

	std::vector<int> lcp_temp_arr(m, 0);
	std::vector<int> inv_suffix(m, 0);

	for (int i = 0; i < m; ++i)
		inv_suffix[suffix_arr[i].first] = i;

	int k = 0;
	for (int i = 0; i < m; ++i) {
		if (inv_suffix[i] == m - 1) {
			k = 0;
			continue;
		}

		int j = suffix_arr[inv_suffix[i] + 1].first;

		while (i + k < m && j + k < m && str[i + k] == str[j + k])
			++k;

		lcp_temp_arr[(inv_suffix[i] + 1) % m] = k;

		if (k)
			--k;
	}

	std::vector<std::pair<int, int>> lcp_arr(m - n);
	for (int i = n; i < m; ++i)
		lcp_arr[i - n] = { lcp_temp_arr[i], suffix_arr[i].second };

	return lcp_arr;
}

void shift_alphabet(std::string& T) {
	for (int i = 0; i < (int)T.size(); ++i)
		T[i] += 4;
}

void unshift_alphabet(std::string& T) {
	for (int i = 0; i < (int)T.size(); ++i) {
		T[i] -= 4;
		if (!T[i])
			T[i] -= 100;
	}
}

void longest_shared_substring(std::vector<std::string>& strs, int n, int k) {
	char sentinel = 1;
	std::string T = "";
	for (auto& str : strs) {
		shift_alphabet(str);
		T += str;
		T += sentinel++;
	}

	std::vector<std::pair<int, int>> SA = suffix_array(T);
	std::vector<std::pair<int, int>> LCP = lcp_array(T, n, SA);

	unshift_alphabet(T);
	std::vector<int> color_count(n, 0);
	int colors_covered = 0;

	int lcs = 0;

	int i = 0;
	int j = 0;

	std::set<std::string> LCS;

	std::deque<int> dque;
	while (j < LCP.size()) {
		while (colors_covered < k && j < LCP.size()) {
			if (!color_count[LCP[j].second])
				++colors_covered;
			++color_count[LCP[j].second];

			while (!dque.empty() && LCP[j].first <= LCP[dque.back()].first)
				dque.pop_back();
			dque.push_back(j);

			++j;
		}

		while (!dque.empty() && dque.front() <= i)
			dque.pop_front();

		if (LCP[dque.front()].first >= lcs && colors_covered >= k) {
			if (LCP[dque.front()].first > lcs)
				LCS.clear();
			lcs = LCP[dque.front()].first;
			std::string lcs_str = T.substr(SA[n + dque.front()].first, lcs);
			LCS.insert(lcs_str);
		}

		--color_count[LCP[i].second];
		if (!color_count[LCP[i].second])
			--colors_covered;
		++i;
	}

	if (!lcs) {
		std::cout << "?\n";
		return;
	}
	for (auto& str : LCS)
		std::cout << str << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	while (n) {
		std::vector<std::string> strs; strs.reserve(n);
		for (int i = 0; i < n; ++i) {
			std::string str;
			std::cin >> str;
			strs.push_back(str);
		}

		int k = (int)ceil((n + 1) / 2.f);
		longest_shared_substring(strs, n, k);

		std::cout << "\n";
		std::cin >> n;
	}

	return 0;
}
