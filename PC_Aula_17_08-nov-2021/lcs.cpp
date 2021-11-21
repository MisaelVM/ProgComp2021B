#include <bits/stdc++.h>

int lcs(std::string& P, std::string& Q, int n, int m) {
	if (n == 0 || m == 0)
		return 0;

	if (P[n - 1] == Q[m - 1])
		return 1 + lcs(P, Q, n - 1, m - 1);

	int tmp1 = lcs(P, Q, n - 1, m);
	int tmp2 = lcs(P, Q, n, m - 1);
	return std::max(tmp1, tmp2);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string P, Q;
	// Caso de prueba 1:
	// Entrada:
	// P = "AXEFDEGRWQVFREQSR"
	// Q = "FDEQVFSDAREQSRSAXEFQR"
	// Salida:
	// 11
	//
	P = "AXEFDEGRWQVFREQSR";
	Q = "FDEQVFSDAREQSRSAXEFQR";
	std::cout << lcs(P, Q, P.size(), Q.size()) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// P = "SADCSAQEWASDQGWRRDFAHYASDWSWEGEGDS"
	// Q = "SADQEWGWRRHYWSEGDS"
	// Salida:
	// 18
	//
	P = "SADCSAQEWASDQGWRRDFAHYASDWSWEGEGDS";
	Q = "SADQEWGWRRHYWSEGDS";
	std::cout << lcs(P, Q, P.size(), Q.size()) << "\n";


	return 0;
}
