#include <iostream>
#include <vector>

std::vector<int> solution(std::string& S, std::vector<int>& P, std::vector<int>& Q) {
	const int DNA_size = (int)S.size();
	std::vector<int> A(DNA_size + 1, 0), C(DNA_size + 1, 0), G(DNA_size + 1, 0), T(DNA_size + 1, 0);
	int i = 1;
	for (auto& nucleotide : S) {
		A[i] = A[i - 1];
		C[i] = C[i - 1];
		G[i] = G[i - 1];
		T[i] = T[i - 1];
		switch (nucleotide) {
		case 'A':
			++A[i];
			break;
		case 'C':
			++C[i];
			break;
		case 'G':
			++G[i];
			break;
		case 'T':
			++T[i];
			break;
		default:
			break;
		}
		++i;
	}

	std::vector<int> queries;
	queries.reserve((int)P.size());
	for (i = 0; i < (int)P.size(); ++i) {
		int a = P[i], b = Q[i];
		if (A[b + 1] - A[a])
			queries.push_back(1);
		else if (C[b + 1] - C[a])
			queries.push_back(2);
		else if (G[b + 1] - G[a])
			queries.push_back(3);
		else
			queries.push_back(4);
	}
	return queries;
}

void print_vector(const std::vector<int>& v) {
	for (auto& i : v)
		std::cout << i << " ";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S = "CAGCCTA";
	std::vector<int> P = { 2, 5, 0 };
	std::vector<int> Q = { 4, 5, 6 };
	// Caso de prueba
	// Entrada:
	// CAGCCTA
	// 2 5 0
	// 4 5 6
	// Salida:
	// 2 4 1

	print_vector(solution(S, P, Q));

	return 0;
}
