#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <string>

int scoreOfParentheses(std::string s) {
	std::stack<std::pair<char, int>> score;
	for (auto i : s) {
		if (i == '(')
			score.push({ i, 0 });
		else {
			if (score.top().first == '(') {
				score.pop();
				score.push({ '#', 1 });
			}
			else {
				int subScoreCount = score.top().second;
				score.pop();
				while (!score.empty() && score.top().first == '#') {
					subScoreCount += score.top().second;
					score.pop();
				}
				score.pop();
				score.push({ '#', 2 * subScoreCount });
			}
			int subScoreCount = score.top().second;
			score.pop();
			while (!score.empty() && score.top().first == '#') {
				subScoreCount += score.top().second;
				score.pop();
			}
			score.push({ '#', subScoreCount });
		}
	}
	return score.top().second;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;

	s = "()";
	std::cout << scoreOfParentheses(s) << "\n";

	s = "(())";
	std::cout << scoreOfParentheses(s) << "\n";

	s = "()()";
	std::cout << scoreOfParentheses(s) << "\n";

	s = "(()(()))";
	std::cout << scoreOfParentheses(s) << "\n";

	return 0;
}
