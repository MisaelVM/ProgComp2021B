#include <bits/stdc++.h>

void flood_fill(std::vector<std::vector<char>>& image, int i, int j) {
	if (image[i][j] == '#')
		return;

	image[i][j] = '#';

	if (i > 0)
		flood_fill(image, i - 1, j);
	if (i < image.size() - 1)
		flood_fill(image, i + 1, j);
	if (j > 0)
		flood_fill(image, i, j - 1);
	if (j < image[0].size() - 1)
		flood_fill(image, i, j + 1);
}

int count_stars(std::vector<std::vector<char>>& image) {
	int stars = 0;

	for (int i = 0; i < image.size(); ++i)
		for (int j = 0; j < image[0].size(); ++j)
			if (image[i][j] == '-') {
				flood_fill(image, i, j);
				++stars;
			}

	return stars;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int m, n, tc = 0;

	while (std::cin >> m >> n) {
		std::vector<std::vector<char>> image;
		image.resize(m);
		for (int i = 0; i < m; ++i) {
			std::cin.get();
			image.reserve(n);
			for (int j = 0; j < n; ++j)
				image[i].push_back(std::cin.get());
		}

		std::cout << "Case " << ++tc << ": " << count_stars(image) << "\n";
	}

	return 0;
}
