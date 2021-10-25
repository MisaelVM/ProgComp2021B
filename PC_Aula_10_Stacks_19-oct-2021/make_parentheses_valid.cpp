#include <iostream>
#include <stack>
#include <vector>
#include <string>

int minAddToMakeValid(std::string s) {
	std::stack<char> validator;
	int adds = 0;
	for (auto& i : s) {
		if (i == '(')
			validator.push(i);
		else if (i == ')' && !validator.empty())
			validator.pop();
		else
			++adds;
	}
	adds += validator.size();
	return adds;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;

	s = "())";
	std::cout << minAddToMakeValid(s) << "\n";

	s = "(((";
	std::cout << minAddToMakeValid(s) << "\n";

	s = "()";
	std::cout << minAddToMakeValid(s) << "\n";

	s = "()))((";
	std::cout << minAddToMakeValid(s) << "\n";

	return 0;
}
