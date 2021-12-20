#include <bits/stdc++.h>

typedef unsigned long long ull;

class Int {
private:
	int number[40];
	int digits;

public:
	Int() {
		std::fill_n(number, 40, 0);
		number[0] = 1;
		digits = 1;
	}

	Int& operator *= (const int num) {
		int d = 0;
		for (int i = 0; i < digits; ++i) {
			int n = number[i] * num + d;
			d = n / 10;
			number[i] = n % 10;
		}

		if (d)
			number[digits++] += d;

		return *this;
	}

	friend std::ostream& operator << (std::ostream& output, const Int& o) {
		for (int i = o.digits - 1; i >= 0; --i)
			output << o.number[i];
		return output;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	ull n;
	std::cin >> n;
	
	while (n) {
		ull p = n - 1;

		std::cout << "{ ";

		int i = 0;
		Int a;
		while (p) {
			if (p & 1) {
				if (i++) std::cout << ", ";
				std::cout << a;
			}

			a *= 3;
			p >>= 1;
		}

		std::cout << " }\n";

		std::cin >> n;
	}

	return 0;
}
