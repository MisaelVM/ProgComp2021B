#include <iostream>
#include <list>

typedef std::list<int> list;
typedef std::list<int>::iterator iter;

list sum(list L1, list L2) {
	list sum_list;
	iter i = L1.begin();
	iter j = L2.begin();

	int n, x, y = 0;
	while (i != L1.end() && j != L2.end()) {
		n = *i + *j + y;
		x = n % 10, y = n / 10;
		sum_list.push_back(x);
		++i; ++j;
	}

	while (i != L1.end()) {
		n = *i + y;
		x = n % 10, y = n / 10;
		sum_list.push_back(x);
		++i;
	}

	while (j != L2.end()) {
		n = *j + y;
		x = n % 10, y = n / 10;
		sum_list.push_back(x);
		++j;
	}

	if (y > 0) sum_list.push_back(y);

	return sum_list;
}

void print_list(const std::list<int>& L) {
	for (auto i : L)
		std::cout << i << " ";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::list<int> L1, L2, L3;
	// Caso de prueba 1
	// Entrada:
	// 3 1 5
	// 5 9 2
	// Salida:
	// 8 0 8
	//
	L1 = { 3, 1, 5 };
	L2 = { 5, 9, 2 };
	L3 = sum(L1, L2);
	print_list(L3);

	// Caso de prueba 2
	// Entrada:
	// 9 9 5 3
	// 4 6 9
	// Salida:
	// 3 6 5 4
	//
	L1 = { 9, 9, 5, 3 };
	L2 = { 4, 6, 9 };
	L3 = sum(L1, L2);
	print_list(L3);

	// Caso de prueba 2
	// Entrada:
	// 9 9 9
	// 9 9 9
	// Salida:
	// 8 9 9 1
	//
	L1 = { 9, 9, 9 };
	L2 = { 9, 9, 9 };
	L3 = sum(L1, L2);
	print_list(L3);

	return 0;
}
