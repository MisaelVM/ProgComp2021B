#include <bits/stdc++.h>
#include <array>

typedef long long int ll;
typedef unsigned long long int ull;
typedef std::array<std::array<ull, 2>, 2> fibo_mat;

constexpr ull MOD = 1000000007;

#define SUMA(A, B) ((A % MOD) + (B % MOD)) % MOD
#define RESTA(A, B) ((A % MOD) - (B % MOD)) % MOD

ll MULT(ll A, ll B) {
	ll res = 0;
	A %= MOD;
 
	while (B) {
		if (B & 1)
			res = (res + A) % MOD;
		A = (2 * A) % MOD;
		B >>= 1;
	}
 
	return res;
}
 

void matrix_2x2_multiplication(fibo_mat& matrix_1, const fibo_mat& matrix_2) {
	ull f_1_n = SUMA(MULT(matrix_1[0][0], matrix_2[0][0]), MULT(matrix_1[0][1], matrix_2[1][0]));
	ull f_n = SUMA(MULT(matrix_1[0][0], matrix_2[0][1]), MULT(matrix_1[0][1], matrix_2[1][1]));
	ull f_n_1 = SUMA(MULT(matrix_1[1][0], matrix_2[0][1]), MULT(matrix_1[1][1], matrix_2[1][1]));

	matrix_1[0][0] = f_1_n % MOD;
	matrix_1[0][1] = matrix_1[1][0] = f_n % MOD;
	matrix_1[1][1] = f_n_1 % MOD;
}

fibo_mat fib_mat_rec(fibo_mat& base_matrix_form, fibo_mat& matrix, ull n) {
	if (n == 1)
		return matrix;

	fib_mat_rec(base_matrix_form, matrix, n / 2);
	matrix_2x2_multiplication(matrix, matrix);

	if (n % 2 == 1)
		matrix_2x2_multiplication(matrix, base_matrix_form);

	return matrix;
}

fibo_mat fib_mat(ull n) {
	fibo_mat matrix_form;
	fibo_mat matrix;
	matrix_form[0][0] = matrix[0][0] = 0;
	matrix_form[0][1] = matrix[0][1] = 1;
	matrix_form[1][0] = matrix[1][0] = 1;
	matrix_form[1][1] = matrix[1][1] = 1;

	if (n <= 1)
		return matrix;
	return fib_mat_rec(matrix_form, matrix, n);
}

int main()
{
	ull a, b, n;

	std::cin >> a >> b >> n;
	while (a || b || n) {
		fibo_mat fa = fib_mat(a);
		fibo_mat fb = fib_mat(b);
		fibo_mat fn = fib_mat(n - 1);

		ull fiboss_number;

		// f_{n-1}	f_n
		// f_n		f_{n+1}

		if (n - 1) {
			ull part1 = MULT(MULT(fa[0][1], fb[0][1]), SUMA(MULT(fn[0][0], fn[0][1]), 1));
			ull part2 = MULT(MULT(fa[1][1], fb[1][1]), MULT(fn[1][0], fn[1][1]));
			ull part3 = SUMA(MULT(fa[1][1], fb[1][0]), MULT(fa[0][1], fb[1][1]));
			ull fc = MULT(fn[0][1], fn[1][0]);
			if (!(n & 1))
				fc = RESTA(fc, 1);

			fiboss_number = SUMA(SUMA(part1, part2), MULT(part3, fc));
		}
		else
			fiboss_number = MULT(fa[0][1], fb[1][0]);

		std::cout << fiboss_number << "\n";

		std::cin >> a >> b >> n;
	}

	return 0;
}
