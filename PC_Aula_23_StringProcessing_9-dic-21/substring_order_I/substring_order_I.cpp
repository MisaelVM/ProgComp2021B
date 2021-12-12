#include <bits/stdc++.h>

typedef unsigned long long ll;

struct suffix {
	ll index; // Original index
	ll rank[2]; // Rank and Next pair
};

int cmp(suffix a, suffix b) {
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1]) : (a.rank[0] < b.rank[0]);
}

std::vector<ll> suffix_array(const std::string& str) {
	ll n = str.size();
	std::vector<suffix> suffixes(n);

	for (ll i = 0; i < n; ++i) {
		suffixes[i].index = i;
		suffixes[i].rank[0] = str[i];
		suffixes[i].rank[1] = ((i + 1) < n) ? (str[i + 1]) : -1;
	}
	
	std::sort(suffixes.begin(), suffixes.end(), cmp);

	std::vector<ll> ind(n);

	for (ll k = 4; k < 2 * n; k *= 2) {
		ll rank = 0;
		ll prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;

		for (ll i = 1; i < n; ++i) {
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

		for (ll i = 0; i < n; ++i) {
			ll nextIndex = suffixes[i].index + k / 2;
			suffixes[i].rank[1] = (nextIndex < n) ? suffixes[ind[nextIndex]].rank[0] : -1;
		}

		std::sort(suffixes.begin(), suffixes.end(), cmp);
	}

	std::vector<ll> suffix_arr(n);
	for (ll i = 0; i < n; ++i)
		suffix_arr[i] = suffixes[i].index;

	return suffix_arr;
}

std::vector<ll> lcp_array(const std::string& str, const std::vector<ll>& suffix_arr) {
	ll n = suffix_arr.size();

	std::vector<ll> lcp_arr(n, 0);
	std::vector<ll> inv_suffix(n, 0);

	for (ll i = 0; i < n; ++i)
		inv_suffix[suffix_arr[i]] = i;

	ll k = 0;
	for (ll i = 0; i < n; ++i) {
		if (inv_suffix[i] == n - 1) {
			k = 0;
			continue;
		}

		ll j = suffix_arr[inv_suffix[i] + 1];

		while (i + k < n && j + k < n && str[i + k] == str[j + k])
			++k;

		lcp_arr[(inv_suffix[i] + 1) % n] = k;

		if (k)
			--k;
	}

	return lcp_arr;
}

std::string substr_order(std::string& str, ll k) {
	std::vector<ll> SA = suffix_array(str);
	std::vector<ll> LCP = lcp_array(str, SA);

	ll n = str.size();

	ll p = 0;
	for (ll i = 0; i < n; ++i) {
		if (p + (n - SA[i]) - LCP[i] >= k) {
			ll j = LCP[i];
			std::string substr = str.substr(SA[i], j);
			while (p < k) {
				substr += str[SA[i] + j];
				++p;
				++j;
			}
			return substr;
		}
		p += (n - SA[i]) - LCP[i];
	}
	return "";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string str;
	ll k;

	std::cin >> str >> k;
	std::cout << substr_order(str, k) << "\n";

	return 0;
}
