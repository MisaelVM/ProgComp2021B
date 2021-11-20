#include <bits/stdc++.h>

void flood_fill(std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& ocean_flood, int i, int j) {
	if (ocean_flood[i][j])
		return;
	
	ocean_flood[i][j] = true;

	if (i > 0 && heights[i][j] <= heights[i - 1][j])
		flood_fill(heights, ocean_flood, i - 1, j);
	if (i < heights.size() - 1 && heights[i][j] <= heights[i + 1][j])
		flood_fill(heights, ocean_flood, i + 1, j);
	if (j > 0 && heights[i][j] <= heights[i][j - 1])
		flood_fill(heights, ocean_flood, i, j - 1);
	if (j < heights[0].size() - 1 && heights[i][j] <= heights[i][j + 1])
		flood_fill(heights, ocean_flood, i, j + 1);
}

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
	std::vector<std::vector<bool>> pacific_ocean(heights.size(), std::vector<bool>(heights[0].size(), false));
	std::vector<std::vector<bool>> atlantic_ocean(heights.size(), std::vector<bool>(heights[0].size(), false));

	for (int i = 0; i < heights.size(); ++i) {
		flood_fill(heights, pacific_ocean, i, 0);
		flood_fill(heights, atlantic_ocean, i, heights[0].size() - 1);
	}

	for (int j = 0; j < heights[0].size(); ++j) {
		flood_fill(heights, pacific_ocean, 0, j);
		flood_fill(heights, atlantic_ocean, heights.size() - 1, j);
	}

	std::vector<std::vector<int>> flow_both;

	for (int i = 0; i < heights.size(); ++i)
		for (int j = 0; j < heights[0].size(); ++j)
			if (pacific_ocean[i][j] && atlantic_ocean[i][j])
				flow_both.push_back({ i, j });

	return flow_both;
}

void print_vector(const std::vector<std::vector<int>>& vec) {
	for (auto& coordinate : vec)
		std::cout << "(" << coordinate[0] << ", " << coordinate[1] << ") ";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> heights;
	// Caso de prueba 1:
	// Entrada:
	// [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
	// Salida:
	// [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
	//
	heights = {
		{ 1, 2, 2, 3, 5 },
		{ 3, 2, 3, 4, 4 },
		{ 2, 4, 5, 3, 1 },
		{ 6, 7, 1, 4, 5 },
		{ 5, 1, 1, 2, 4 }
	};
	print_vector(pacificAtlantic(heights));

	// Caso de prueba 2:
	// Entrada:
	// [[2,1],[1,2]]
	// Salida:
	// [[0,0],[0,1],[1,0],[1,1]]
	//
	heights = {
		{ 2, 1 },
		{ 1, 2 }
	};
	print_vector(pacificAtlantic(heights));

	return 0;
}
