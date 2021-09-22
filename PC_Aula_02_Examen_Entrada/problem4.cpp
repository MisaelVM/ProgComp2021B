#include <iostream>
#include <stack>

void sort_stack(std::stack<int>& S) {
	std::stack<int> aux1, aux2;

	while (!S.empty()) {
		int item = S.top(); S.pop();
		while (!aux1.empty() && aux1.top() > item) {
			aux2.push(aux1.top()); aux1.pop();
		}
		aux1.push(item);
		while (!aux2.empty()) {
			aux1.push(aux2.top()); aux2.pop();
		}
	}

	S = aux1;
}

void print_stack(std::stack<int> S) {
	std::stack<int> aux;
	while (!S.empty()) { aux.push(S.top()); S.pop(); }

	while (!aux.empty()) {
		std::cout << aux.top() << " ";
		aux.pop();
	}
	std::cout << "\n";
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// Caso de prueba 1
	// Entrada:
	// 75 56 23 21 49 32
	// Salida:
	// 21 23 32 49 56 75
	//
	std::stack<int> S1;
	S1.push(75);
	S1.push(56);
	S1.push(23);
	S1.push(21);
	S1.push(49);
	S1.push(32);
	sort_stack(S1);
	print_stack(S1);

	// Caso de prueba 2
	// Entrada:
	// 23 102 64 98 43 15
	// Salida:
	// 15 23 43 64 98 102
	//
	std::stack<int> S2;
	S2.push(23);
	S2.push(102);
	S2.push(64);
	S2.push(98);
	S2.push(43);
	S2.push(15);
	sort_stack(S2);
	print_stack(S2);

	return 0;
}
