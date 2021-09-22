#include <iostream>

int fibo(int n) {
	if (n <= 1)
		return n;

	int f_n_prev = 0, f_n = 1, f_n_next;
	for (int i = 1; i < n; ++i) {
		f_n_next = f_n_prev + f_n;
		f_n_prev = f_n;
		f_n = f_n_next;
	}
	return f_n;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::cout << fibo(n) << "\n";

	return 0;
}
