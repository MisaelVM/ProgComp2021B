#include <bits/stdc++.h>

int lcs_bottomup(std::string& P, std::string& Q) {
	int n = P.size();
	int m = Q.size();
	std::vector<std::vector<int>> LCS(n + 1, std::vector<int>(m + 1));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (P[i - 1] == Q[j - 1])
				LCS[i][j] = 1 + LCS[i - 1][j - 1];
			else
				LCS[i][j] = std::max(LCS[i - 1][j], LCS[i][j - 1]);

	return LCS[n][m];
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
	std::cout << lcs_bottomup(P, Q) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// P = "SADCSAQEWASDQGWRRDFAHYASDWSWEGEGDS"
	// Q = "SADQEWGWRRHYWSEGDS"
	// Salida:
	// 18
	//
	P = "SADCSAQEWASDQGWRRDFAHYASDWSWEGEGDS";
	Q = "SADQEWGWRRHYWSEGDS";
	std::cout << lcs_bottomup(P, Q) << "\n";


	return 0;
}
