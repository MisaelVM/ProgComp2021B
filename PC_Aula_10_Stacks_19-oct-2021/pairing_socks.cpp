#include <iostream>
#include <stack>

int pairSocks(std::stack<int> socks) {
	std::stack<int> aux;
	int numSocks = socks.size();

	for (int i = 0; i < numSocks; ++i) {
		int sock = socks.top(); socks.pop();
		if (!aux.empty() && aux.top() == sock)
			aux.pop();
		else
			aux.push(sock);
	}

	return (aux.empty()) ? numSocks : -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::stack<int> socks;
	int n, a;
	std::cin >> n;
	for (int i = 0; i < 2 * n; ++i) {
		std::cin >> a;
		socks.push(a);
	}

	int moves = pairSocks(socks);
	(moves < 0) ? std::cout << "impossible\n" : std::cout << moves << "\n";

	return 0;
}
