#include <bits/stdc++.h>

void dfs(std::vector<std::vector<int>>& rooms, int at, std::vector<bool>& visited) {
	if (visited[at])
		return;
	visited[at] = true;
	for (auto& i : rooms[at])
		dfs(rooms, i, visited);
}

bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
	std::vector<bool> visited(rooms.size(), false);
	
	dfs(rooms, 0, visited);

	for (int i = 0; i < visited.size(); ++i)
		if (!visited[i])
			return false;
	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::vector<int>> rooms;

	// Caso de prueba 1:
	// Entrada:
	// [[1],[2],[3],[]]
	// Salida:
	// true
	//
	rooms = { { 1 }, { 2 }, { 3 }, {  } };
	std::cout << canVisitAllRooms(rooms) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// [[1,3],[3,0,1],[2],[0]]
	// Salida:
	// false
	//
	rooms = { { 1, 3 }, { 3, 0, 1 }, { 2 }, { 0 } };
	std::cout << canVisitAllRooms(rooms) << "\n";

	return 0;
}
