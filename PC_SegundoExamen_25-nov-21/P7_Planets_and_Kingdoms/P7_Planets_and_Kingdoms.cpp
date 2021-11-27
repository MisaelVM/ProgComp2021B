#include <bits/stdc++.h>

typedef std::vector<int> vi;
typedef std::vector<vi> graph;
typedef std::vector<bool> vb;
typedef std::stack<int> stck;

void dfs(const graph& adjacencyList, int at, int& count, int& kingdoms, vi& lowlink, vi& visited, vb& onStack, stck& stack) {
	stack.push(at);
	onStack[at] = true;
	visited[at] = lowlink[at] = count++;

	for (auto& to : adjacencyList[at]) {
		if (visited[to] == -1)
			dfs(adjacencyList, to, count, kingdoms, lowlink, visited, onStack, stack);
		if (onStack[to])
			lowlink[at] = std::min(lowlink[at], lowlink[to]);
	}

	if (visited[at] == lowlink[at]) {
		int node = stack.top(); stack.pop();
		while (true) {
			onStack[node] = false;
			lowlink[node] = kingdoms;
			if (node == at)
				break;
			node = stack.top(); stack.pop();
		}
		++kingdoms;
	}
}

vi scc(graph& adjacencyList, int n, int& kingdoms) {
	vi lowlink(n, 0);
	vb onStack(n, false);
	stck stack;

	int count = 0;
	vi visited(n, -1);
	for (int i = 0; i < n; ++i)
		if (visited[i] == -1)
			dfs(adjacencyList, i, count, kingdoms, lowlink, visited, onStack, stack);

	return lowlink;
}

void check_kingdoms(graph& adjacencyList) {
	int n = adjacencyList.size();
	int kingdoms = 0;

	vi planets_kingdom = scc(adjacencyList, n, kingdoms);
	std::cout << kingdoms << "\n";
	for (auto& i : planets_kingdom)
		std::cout << i + 1 << " ";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	graph adjacencyList;
	int n, m, a, b;
	std::cin >> n >> m;

	adjacencyList.resize(n);
	for (int i = 0; i < m; ++i) {
		std::cin >> a >> b;
		adjacencyList[a - 1].push_back(b - 1);
	}

	check_kingdoms(adjacencyList);

	return 0;
}
