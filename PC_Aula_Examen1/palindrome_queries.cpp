#include <iostream>
#include <string>
#include <vector>

void update(std::vector<std::vector<bool>>& table, std::string& str, int k, char u) {
	str[k - 1] = u;
	const int n = str.size();
	for (int j = 0; j < n; ++j)
		for (int i = 0; i < n - j; ++i)
			if (str[i] == str[i + j])
				table[i][i + j] = (j < 2) ? true : table[i + 1][i + j - 1];
			else
				table[i][i + j] = false;
}

bool query(const std::vector<std::vector<bool>>& table, int a, int b) {
	return table[a - 1][b - 1];
}

void construct_table(std::vector<std::vector<bool>>& table, const std::string& str) {
	const int n = str.size();
	table.resize(n, std::vector<bool>(n, false));
	for (int j = 0; j < n; ++j)
		for (int i = 0; i < n - j; ++i)
			if (str[i] == str[i + j])
				table[i][i + j] = (j < 2) ? true : table[i + 1][i + j - 1];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string str;
	int n, m;
	std::cin >> n >> m >> str;

	std::vector<std::vector<bool>> lookup_table;
	construct_table(lookup_table, str);

	std::vector<bool> queries;

	int op, a, b;
	char u;
	for (int i = 0; i < m; ++i) {
		std::cin >> op >> a;
		if (op == 1) {
			std::cin >> u;
			update(lookup_table, str, a, u);
		}
		else if (op == 2) {
			std::cin >> b;
			queries.push_back(query(lookup_table, a, b));
		}
	}

	for (auto i : queries)
		std::cout << ((i) ? "YES\n" : "NO\n");


	return 0;
}
