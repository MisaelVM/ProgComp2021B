#include <iostream>
#include <queue>

std::string caps_lock(std::string s) {
	std::string msg = "";
	std::queue<char> buffer;
	bool shift = false;

	for (auto& i : s) {
		if (i == '@') {
			shift ^= true;
		}
		else if (i == '$') {
			while (!buffer.empty()) {
				msg += (buffer.front() - (32 * shift));
				buffer.pop();
			}
		}
		else {
			buffer.push(i);
		}
	}
	return msg;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// Caso de prueba:
	// Entrada:
	// abc$d@ef$@g$
	// Salida:
	// abcDEFg
	//
	std::string s = "abc$d@ef$@g$";
	std::cout << caps_lock(s) << "\n";

	return 0;
}
