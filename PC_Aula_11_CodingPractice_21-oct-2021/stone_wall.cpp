#include <iostream>
#include <vector>
#include <stack>

int solution(std::vector<int>& H) {
	std::stack<int> aux;

	int last_stacked = 0;
	int blocks = 0;

	for (auto& i : H) {
		if (i > last_stacked) {
			last_stacked = i;
			++blocks;
			aux.push(i);
		}
		else if (i < last_stacked) {
			while (!aux.empty() && i < aux.top())
				aux.pop();
			if (aux.empty() || i != aux.top()) {
				aux.push(i);
				++blocks;
			}
			last_stacked = i;
		}
	}

	return blocks;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// Caso de prueba:
	// Entrada:
	// 8 8 5 7 9 8 7 4 8
	// Salida:
	// 7
	//
	std::vector<int> H = { 8, 8, 5, 7, 9, 8, 7, 4, 8 };
	std::cout << solution(H) << "\n";

	return 0;
}
