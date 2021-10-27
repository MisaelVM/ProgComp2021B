#include <iostream>
#include <stack>
#include <string>

int solution(std::string& S) {
	std::stack<char> validator;
	for (auto& i : S) {
		switch (i) {
		case '(':
			validator.push(i);
			break;
		case ')':
			if (validator.empty() || validator.top() != '(')
				return 0;
			validator.pop();
			break;
		default:
			return 0;
		}
	}
	return validator.empty();
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;

	// Caso de prueba 1
	// Entrada:
	// (()(())())
	// Salida:
	// 1
	//
	S = "(()(())())";
	std::cout << solution(S) << "\n";

	// Caso de prueba 1
	// Entrada:
	// (()(())())
	// Salida:
	// 0
	//
	S = "())";
	std::cout << solution(S) << "\n";

	return 0;
}
