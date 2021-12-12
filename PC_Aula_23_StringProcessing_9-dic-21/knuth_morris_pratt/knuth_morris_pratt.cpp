#include <bits/stdc++.h>

std::vector<int> KMP_array(const std::string& P) {
	int m = P.size();

	std::vector<int> F(m, 0);

	int i = 1, j = 0;
	while (i < m) {
		if (P[i] == P[j]) {
			F[i] = j + 1;
			++i;
			++j;
		}
		else if (j > 0)
			j = F[j - 1];
		else {
			F[i] = 0;
			++i;
		}
	}

	return F;
}

int KMP(const std::string& T, const std::string& P) {
	int n = T.size();
	int m = P.size();

	std::vector<int> F = KMP_array(P);

	int i = 0, j = 0;

	while (i < n) {
		if (P[j] == T[i]) {
			if (j == m - 1)
				return i - m + 1;
			++i;
			++j;
		}
		else if (j > 0)
			j = F[j - 1];
		else
			++i;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string T, P;

	// Caso de prueba 1
	// Entrada:
	// T = "PARTICIPARIA CON MI PARACAIDAS PARTICULAR"
	// P = "PARA"
	// Salida:
	// 20
	//
	T = "PARTICIPARIA CON MI PARACAIDAS PARTICULAR";
	P = "PARA";
	std::cout << KMP(T, P) << "\n";

	// Caso de prueba 2
	// Entrada:
	// T = "PARTICIPARIA CON MI PARACAIDAS PARTICULAR"
	// P = "PARTIC"
	// Salida:
	// 20
	//
	T = "PARTICIPARIA CON MI PARACAIDAS PARTICULAR";
	P = "PARTIC";
	std::cout << KMP(T, P) << "\n";

	return 0;
}
