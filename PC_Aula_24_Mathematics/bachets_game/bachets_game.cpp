#include <bits/stdc++.h>

void play(int n, const std::vector<int>& legal_moves) {
	std::vector<bool> game_states(n + 1, false);

	for (int i = 0; i <= n; ++i)
		if (!game_states[i])
			for (auto& j : legal_moves)
				if (i + j <= n)
					game_states[i + j] = true;

	if (game_states[n])
		std::cout << "Stan wins\n";
	else
		std::cout << "Ollie wins\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	while (std::cin >> n) {
		std::cin >> m;
		std::vector<int> legal_moves(m);
		for (int i = 0; i < m; ++i)
			std::cin >> legal_moves[i];
		play(n, legal_moves);
	}

	return 0;
}
