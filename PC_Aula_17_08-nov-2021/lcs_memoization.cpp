#include <bits/stdc++.h>

int lcs_memoized(std::string& P, std::string& Q, int n, int m, std::vector<std::vector<int>>& memo) {
	if (memo[n][m] != -1)
		return memo[n][m];

	int result;
	if (n == 0 || m == 0)
		result = 0;
	else if (P[n - 1] == Q[m - 1])
		result = 1 + lcs_memoized(P, Q, n - 1, m - 1, memo);
	else {
		int tmp1 = lcs_memoized(P, Q, n - 1, m, memo);
		int tmp2 = lcs_memoized(P, Q, n, m - 1, memo);
		result = std::max(tmp1, tmp2);
	}

	memo[n][m] = result;
	return result;
}

int lcs(std::string& P, std::string& Q) {
	int n = P.size();
	int m = Q.size();
	std::vector<std::vector<int>> memo(n + 1, std::vector<int>(m + 1, -1));
	return lcs_memoized(P, Q, n, m, memo);
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
	std::cout << lcs(P, Q) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// P = "SADCSAQEWASDQGWRRDFAHYASDWSWEGEGDS"
	// Q = "SADQEWGWRRHYWSEGDS"
	// Salida:
	// 18
	//
	P = "SADCSAQEWASDQGWRRDFAHYASDWSWEGEGDS";
	Q = "SADQEWGWRRHYWSEGDS";
	std::cout << lcs(P, Q) << "\n";


	return 0;
}
