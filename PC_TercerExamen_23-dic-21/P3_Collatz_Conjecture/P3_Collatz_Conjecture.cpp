#include <bits/stdc++.h>
#include <unordered_map>

typedef long long ll;

ll next_collatz(ll& n) {
	n = (n & 1) ? 3 * n + 1 : n / 2;
	return n;
}

void collatz_meet_at(ll A, ll B) {
	std::unordered_map<ll, ll> collatz;

	ll a = A, at = B;
	ll i = 0;

	collatz[a] = i++;
	while (a != 1) {
		next_collatz(a);
		collatz[a] = i++;
	}

	ll b_steps = 0;
	while (!collatz.count(at)) {
		next_collatz(at);
		++b_steps;
	}

	ll a_steps = collatz[at];

	std::cout << A << " needs " << a_steps << " steps, ";
	std::cout << B << " needs " << b_steps << " steps, ";
	std::cout << "they meet at " << at << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll A, B;
	while (std::cin >> A >> B && A && B)
		collatz_meet_at(A, B);

	return 0;
}
