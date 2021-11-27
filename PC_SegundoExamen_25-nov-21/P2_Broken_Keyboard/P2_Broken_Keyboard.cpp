#include <bits/stdc++.h>
#include <unordered_map>

int maxWritable(std::string text, int m) {
	std::unordered_map<char, int> working_keys;

	int i = 0;
	int j = 0;
	int substr_size = 0;
	int total_working_keys = 0;

	working_keys[text[0]] = 1;
	total_working_keys = 1;

	for (int k = 1; k < text.size(); ++k) {
		if (!working_keys.count(text[k])) {
			working_keys[text[k]] = 1;
			++total_working_keys;
		}
		else {
			if (!working_keys[text[k]])
				++total_working_keys;
			++working_keys[text[k]];
		}
		++j;

		while (total_working_keys > m) {
			--working_keys[text[i]];
			if (!working_keys[text[i]])
				--total_working_keys;
			++i;
		}

		if (j - i + 1 > substr_size)
			substr_size = j - i + 1;
	}

	return substr_size;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int m;
	std::string text;

	std::cin >> m;
	while (m) {
		std::getline(std::cin >> std::ws, text);
		std::cout << maxWritable(text, m) << "\n";
		std::cin >> m;
	}

	return 0;
}
