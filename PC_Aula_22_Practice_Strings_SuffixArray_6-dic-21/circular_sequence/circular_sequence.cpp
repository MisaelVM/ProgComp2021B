#include <bits/stdc++.h>

void lex_smallest_seq(std::string& seq) {
	std::string circ_seq = seq;
	circ_seq += seq;
	
	std::map<std::string, int> M;
	const char* cad = circ_seq.c_str();
	for (int i = 0; i < seq.size(); ++i, ++cad)
		M[cad] = i;

	auto a = M.begin();
	for (int i = 0; i < seq.size(); ++i)
		seq[i] = circ_seq[a->second + i];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::string sequence;

	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> sequence;
		lex_smallest_seq(sequence);
		std::cout << sequence << "\n";
	}

	return 0;
}
