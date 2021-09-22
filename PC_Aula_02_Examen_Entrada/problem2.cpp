#include <iostream>
#include <unordered_set>
#include <list>

typedef std::list<int>::iterator iter;

void delete_duplicates(std::list<int>& L) {
	std::unordered_set<int> H;
	iter itr = L.begin();
	while (itr != L.end()) {
		if (H.find(*itr) == H.end()) {
			H.insert(*itr);
			++itr;
		}
		else {
			iter itr_temp = itr;
			++itr;
			L.erase(itr_temp);
		}
	}
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

	std::list<int> L;
	// Caso de prueba 1
	// Entrada:
	// 1 1 2 2 3
	// Salida:
	// 1 2 3
	//
	L = { 1, 1, 2, 2, 3 };
	delete_duplicates(L);
	print_list(L);

	// Caso de prueba 2
	// Entrada:
	// 5 6 7 7 3 9 5 4 2 6 1
	// Salida:
	// 5 6 7 3 9 4 2 1
	//
	L = { 5, 6, 7, 7, 3, 9, 5, 4, 2, 6, 1 };
	delete_duplicates(L);
	print_list(L);

	return 0;
}
