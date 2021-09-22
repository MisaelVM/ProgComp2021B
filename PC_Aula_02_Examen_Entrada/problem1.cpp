#include <iostream>
#include <unordered_map>
#include <string>

bool check_anagram(std::string cad1, std::string cad2) {
	std::unordered_map<char, int> H;

	const char* ptr_cad = cad1.c_str();
	while (*ptr_cad) {
		if (H.find(*ptr_cad) == H.end()) {
			H[*ptr_cad] = 1;
		}
		else {
			++H[*ptr_cad];
		}
		++ptr_cad;
	}

	ptr_cad = cad2.c_str();
	while (*ptr_cad) {
		if (H.find(*ptr_cad) == H.end())
			return false;
		else
			--H[*ptr_cad];
		++ptr_cad;
	}

	for (auto& i : H)
		if (i.second)
			return false;
	return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

	// Caso de prueba 1
	// Entrada:
	// LAMINA ANIMAL
	// Salida:
	// 1
	//
	std::cout << check_anagram("LAMINA", "ANIMAL") << "\n";

	// Caso de prueba 2
	// Entrada:
	// MUNT NUTH
	// Salida:
	// 0
	//
	std::cout << check_anagram("MUNT", "NUTH") << "\n";

	return 0;
}
