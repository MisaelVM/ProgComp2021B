#include <iostream>
#include <deque>
#include <cmath>
#include <vector>

typedef long long ll;
typedef long double ld;

ll add(ll a, ll b, ll c) {
	return ((a % c) + (b % c)) % c;
}

ll multiply(ll a, ll b, ll c) {
	// a * b = D
	// D = dq + r
	// q = floor(D / q)
	ll quotient = (ld)a * (ld)b / (ld)c;
	// r = D - dq
	ll remainder = ((ll)a * (ll)b) - ((ll)c * quotient);

	// shifting r
	remainder = (remainder + (c * 4)) % c;

	return remainder;
}

ll min_heights_sum(std::vector<std::vector<ll>> field, ll K) {
	const ll N = field.size();
	const ll mod = 1e9 + 7;

	std::vector<std::vector<ll>> minimum_field(N);
	for (ll i = 0; i < N; ++i) {
		minimum_field[i].resize(N);
		std::deque<ll> row_minimums;
		for (ll j = 0; j < N; ++j) {
			if (j - (ll)K >= 0 && !row_minimums.empty() && row_minimums.front() == field[i][j - K])
				row_minimums.pop_front();
			while (!row_minimums.empty() && field[i][j] < row_minimums.back())
				row_minimums.pop_back();
			row_minimums.push_back(field[i][j]);
			minimum_field[i][j] = row_minimums.front();
		}
	}

	ll minimum_heights_sum = 0;
	for (ll j = K - 1; j < N; ++j) {
		std::deque<ll> column_minimums;
		for (ll i = 0; i < N; ++i) {
			if (i - (ll)K >= 0 && !column_minimums.empty() && column_minimums.front() == minimum_field[i - K][j])
				column_minimums.pop_front();
			while (!column_minimums.empty() && minimum_field[i][j] < column_minimums.back())
				column_minimums.pop_back();
			column_minimums.push_back(minimum_field[i][j]);

			if (i - (ll)K + 1 >= 0)
				minimum_heights_sum = add(minimum_heights_sum, column_minimums.front(), mod);
		}
	}
	return minimum_heights_sum;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<ll>> field;
	ll N, K, x, a, b, c;
	std::cin >> N >> K;
	field.resize(N);
	for (ll i = 0; i < N; ++i) {
		field[i].resize(N);
		std::cin >> x >> a >> b >> c;
		a %= c;
		b %= c;
		for (ll j = 0; j < N; ++j) {
			field[i][j] = x;
			x = add(multiply(x, a, c), b, c);
		}
	}

	std::cout << min_heights_sum(field, K) << "\n";

	return 0;
}
