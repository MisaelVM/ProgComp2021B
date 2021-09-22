#include <iostream>

int bits_to_transform(int a, int b) {
	int count = 0;
	while (a || b) {
		count += (a & 1) ^ (b & 1);
		a >>= 1;
		b >>= 1;
	}
	return count;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// Caso de prueba 1
	// Entrada:
	// 31 14
	// Salida:
	// 2
	//
	std::cout << bits_to_transform(31, 14) << "\n";

	// Caso de prueba 2
	// Entrada:
	// 548 789
	// Salida:
	// 4
	//
	std::cout << bits_to_transform(548, 789) << "\n";

	return 0;
}
