#include <iostream>
#include <utility>
#include <vector>
#include <stack>

int solution(std::vector<int>& A, std::vector<int>& B) {
	std::stack<std::pair<int, int>> living_fish;
	const int total_fish = A.size();
	for (int i = 0; i < total_fish; ++i) {
		while (!living_fish.empty() && B[i] < living_fish.top().second && A[i] > living_fish.top().first)
			living_fish.pop();
		if (!living_fish.empty() && A[i] < living_fish.top().first)
			continue;
		living_fish.push({ A[i], B[i] });
	}

	return living_fish.size();
}

int main()
{
	// Caso de prueba:
	// Entrada:
	// 4 3 2 1 5
	// 0 1 0 0 0
	// Salida:
	// 2
	//
	std::vector<int> A = { 4, 3, 2, 1, 5 };
	std::vector<int> B = { 0, 1, 0, 0, 0 };

	std::cout << solution(A, B) << "\n";

	return 0;
}
