#include <bits/stdc++.h>

void dfs(const std::vector<std::set<int>>& adjacencyList, int at, std::vector<bool>& visited, std::set<char>& vertices) {
    if (visited[at])
        return;
    visited[at] = true;
    vertices.insert(at + 'a');
    for (auto& i : adjacencyList[at])
        dfs(adjacencyList, i, visited, vertices);
}

std::vector<std::set<char>> connected_components(const std::vector<std::set<int>>& adjacencyList) {
	std::vector<std::set<char>> components;
	int nro_components = 0;

	std::vector<bool> visited(adjacencyList.size(), false);
	for (int i = 0; i < (int)adjacencyList.size(); ++i) {
		if (!visited[i]) {
			components.push_back({});
			dfs(adjacencyList, i, visited, components[nro_components]);
			++nro_components;
		}
	}

	return components;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<std::set<char>>> solutions;
	int N, V, E;
	std::cin >> N;
	for (int n = 0; n < N; ++n) {
		std::vector<std::set<int>> adjacencyList;
		std::cin >> V >> E;

		adjacencyList.resize(V);
		for (int e = 0; e < E; ++e) {
			char node_from, node_to;
			std::cin >> node_from >> node_to;
			adjacencyList[node_from - 'a'].insert(node_to - 'a');
			adjacencyList[node_to - 'a'].insert(node_from - 'a');
		}

		solutions.push_back(connected_components(adjacencyList));
	}

	int i = 0;
	for (auto& connected_component : solutions) {
		std::cout << "Case #" << i + 1 << ":\n";
		for (auto& component : connected_component) {
			for (auto& vertex : component) {
				std::cout << vertex << ",";
			}
			std::cout << "\n";
		}
		std::cout << connected_component.size() << " connected components\n\n";
		++i;
	}

	return 0;
}
