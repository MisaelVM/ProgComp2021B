#include <iostream>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> get_neighbours(std::vector<std::vector<int>>& color, int i, int j) {
	std::vector<std::pair<int, int>> neighbours;

	if (i > 0)
		neighbours.push_back({ i - 1, j });
	if (i < color.size() - 1)
		neighbours.push_back({ i + 1, j });
	if (j > 0)
		neighbours.push_back({ i, j - 1 });
	if (j < color[0].size() - 1)
		neighbours.push_back({ i, j + 1 });

	return neighbours;
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
	if (image[sr][sc] == newColor)
		return image;

	int tmp = image[sr][sc];
	image[sr][sc] = newColor;
	for (auto& neighbour : get_neighbours(image, sr, sc))
		if (image[neighbour.first][neighbour.second] == tmp)
			floodFill(image, neighbour.first, neighbour.second, newColor);
	return image;
}

void print_matrix(const std::vector<std::vector<int>>& matrix) {
	for (auto& row : matrix) {
		for (auto& i : row)
			std::cout << i << " ";
		std::cout << "\n";
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> G;
	int sr, sc, newColor;

	// Caso de prueba 1
	// Entrada:
	// 1 1 1
	// 1 1 0
	// 1 0 1
	// 1
	// 1
	// 2
	// Salida:
	// 2 2 2
	// 2 2 0
	// 2 0 1
	G = {
			{ 1, 1, 1 },
			{ 1, 1, 0 },
			{ 1, 0, 1 }
		};
	sr = 1;
	sc = 1;
	newColor = 2;
	print_matrix(floodFill(G, sr, sc, newColor));

	// Caso de prueba 2
	// Entrada:
	// 0 0 0
	// 0 0 0
	// 0
	// 0
	// 2
	// Salida:
	// 2 2 2
	// 2 2 2
	G = {
			{ 0, 0, 0 },
			{ 0, 0, 0 },
		};
	sr = 0;
	sc = 0;
	newColor = 2;
	print_matrix(floodFill(G, sr, sc, newColor));

	return 0;
}
