#include <iostream>
#include <string>
#include <vector>
#include <stack>

int precedende_level(char op) {
	switch (op)  {
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

std::string convert_to_postfix(const std::string& expression) {
	std::string postfix_expression = "";
	std::stack<int> aux;
	for (auto& i : expression) {
		switch (i) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			while (!aux.empty() && precedende_level(i) <= precedende_level(aux.top())) {
				postfix_expression += aux.top();
				aux.pop();
			}
			aux.push(i);
			break;
		case '(':
			aux.push(i);
			break;
		case ')':
			while (aux.top() != '(') {
				postfix_expression += aux.top();
				aux.pop();
			}
			aux.pop();
			break;
		default:
			postfix_expression += i;
			break;
		}
	}

	while (!aux.empty()) {
		postfix_expression += aux.top();
		aux.pop();
	}

	return postfix_expression;
}

void print_vector(const std::vector<std::string>& vec) {
	for (auto& i : vec)
		std::cout << i << "\n";
}

int main()
{
	std::string expression;
	std::vector<std::string> postfix_expressions;
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> expression;
		postfix_expressions.push_back(convert_to_postfix(expression));
	}

	print_vector(postfix_expressions);

	return 0;
}
