#include <bits/stdc++.h>

typedef long long ll;

std::vector<ll> eratosthenes(ll n) {
	std::vector<bool> isMarked(n + 1, false);

	std::vector<ll> primes;

	ll i = 2;
	for (; i * i <= n; ++i) {
		if (!isMarked[i]) {
			primes.push_back(i);
			for (ll j = i; j <= n; j += i)
				isMarked[j] = true;
		}
	}

	for (; i <= n; ++i)
		if (!isMarked[i])
			primes.push_back(i);

	return primes;
}

bool common_factor(const std::map<ll, ll>& factors, ll p) {
	for (auto& factor : factors)
		if (factor.second % p != 0)
			return false;
	return true;
}

ll largest_pth_power(ll n) {
	bool isNegative = false;
	if (n < 0) {
		isNegative = true;
		n = -n;
	}

	ll max_pth_power = static_cast<ll>(std::log2(n));
	std::map<ll, ll> factors;

	std::vector<ll> primes = eratosthenes(static_cast<ll>(sqrt(n + 1)));
	for (ll i = 0; i < primes.size() && n > 1; ++i) {
		ll prime = primes[i], power = 0;
		while (n % prime == 0) {
			++power;
			n /= prime;
		}
		if (power)
			factors[prime] = power;
	}

	if (n > 1)
		factors[n] = 1;

	ll perfect_power = max_pth_power;
	while (perfect_power) {
		if(common_factor(factors, perfect_power) && (!isNegative || (perfect_power & 1)))
			return perfect_power;
		--perfect_power;
	}

	return perfect_power;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	ll n;
	std::cin >> n;

	while (n) {
		std::cout << largest_pth_power(n) << "\n";
		std::cin >> n;
	}

	return 0;
}