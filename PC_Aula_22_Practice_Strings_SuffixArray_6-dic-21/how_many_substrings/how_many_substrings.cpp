#include <bits/stdc++.h>

constexpr int MAX_LENGTH = 2e5 + 1;

struct State {
	int len, prev;
	long long num_paths;
	std::map<int, int> adj;
};

class SuffixAutomaton {
private:
	std::vector<State> DFA;
	int tot;
	int sink;
	long long tot_paths;

public:
	SuffixAutomaton(int n) {
		DFA.resize(n);
		clear();
	}

	void extend_automaton(char ch) {
		int cc = ch - 'a';

		int tail = tot++;
		DFA[tail].len = DFA[sink].len + 1;
		DFA[tail].adj.clear();
		DFA[tail].num_paths = 0;

		int curr = sink;
		while (curr != -1 && !DFA[curr].adj.count(cc)) {
			DFA[curr].adj[cc] = tail;
			DFA[tail].num_paths += DFA[curr].num_paths;
			tot_paths += DFA[curr].num_paths;
			curr = DFA[curr].prev;
		}

		if (curr == -1)
			DFA[tail].prev = 0;
		else {
			int nxt = DFA[curr].adj[cc];
			if (DFA[nxt].len == DFA[curr].len + 1)
				DFA[tail].prev = nxt;
			else {
				int cl = tot++;
				DFA[cl].len = DFA[curr].len + 1;
				DFA[cl].adj = DFA[nxt].adj;
				DFA[cl].num_paths = 0;
				DFA[cl].prev = DFA[nxt].prev;
				while (curr != -1 && DFA[curr].adj[cc] == nxt) {
					DFA[curr].adj[cc] = cl;
					DFA[nxt].num_paths -= DFA[curr].num_paths;
					DFA[cl].num_paths += DFA[curr].num_paths;
					curr = DFA[curr].prev;
				}

				DFA[tail].prev = DFA[nxt].prev = cl;
			}
		}

		sink = tail;
	}

	long long different_substrs() const { return tot_paths; }

	void clear() {
		DFA[0].len = 0;
		DFA[0].prev = -1;
		DFA[0].adj.clear();
		DFA[0].num_paths = 1;
		sink = 0;
		tot = 1;
		tot_paths = 0;
	}
};

void run_program(std::string instructions, SuffixAutomaton& SA) {
	for (auto& instruction : instructions)
		if (instruction == '?')
			std::cout << SA.different_substrs() << "\n";
		else
			SA.extend_automaton(instruction);
	SA.clear();
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string instructions;

	SuffixAutomaton SA(2 * MAX_LENGTH);
	while (std::cin >> instructions)
		run_program(instructions, SA);

	return 0;
}
