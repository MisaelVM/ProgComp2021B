#include <iostream>
#include <deque>

std::string backspace(std::string s) {
	std::deque<char> msg;

	for (auto& i : s) {
		if (i == '#')
			msg.pop_back();
		else
			msg.push_back(i);
	}

	std::string msg_str = "";
	while (!msg.empty()) {
		msg_str += msg.front();
		msg.pop_front();
	}
	return msg_str;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;

	// Caso de prueba:
	// Entrada:
	// abc#de##f#ghi#jklmn#op#
	// Salida:
	// abghjklmo
	//
	s = "abc#de##f#ghi#jklmn#op#";
	std::cout << backspace(s) << "\n";

	return 0;
}
