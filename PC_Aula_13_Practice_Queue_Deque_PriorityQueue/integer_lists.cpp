#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <deque>

std::deque<int> parse_list(std::string list) {
	std::deque<int> parsed_list;

	int j = 1;
	list.erase(0, j); list.pop_back();
	while (j > 0 && list.size()) {
		j = list.find(',');
		std::string token = list.substr(0, j);
		parsed_list.push_back(std::stoi(token));
		list.erase(0, j + 1);
	}

	return parsed_list;
}

std::string prepare_output(std::deque<int>& nums, bool is_reversed) {
	std::string output = "[";

	const int nums_size = nums.size();

	if (nums_size)
		output += std::to_string(nums[(nums_size - 1) * is_reversed]);

	for (int i = 1; i < nums_size; ++i) {
		output += ",";
		output += std::to_string(nums[(nums_size - 1) * is_reversed + i * pow(-1, is_reversed)]);
	}

	output += "]";
	return output;
}

std::string runBAPC(std::deque<int>& nums, std::string functions) {
	bool reversed = false;
	for (auto& func : functions) {
		if (func == 'R')
			reversed ^= true;
		else {
			if (nums.empty())
				return "error";

			if (reversed)
				nums.pop_back();
			else
				nums.pop_front();
		}
	}
	return prepare_output(nums, reversed);
}

void print_vector(const std::vector<std::string>& vec) {
	for (auto& i : vec)
		std::cout << i << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::string> outputs;
	int TC;
	std::cin >> TC;
	for (int i = 0; i < TC; ++i) {
		std::string p, list;
		int n;
		std::cin >> p >> n >> list;
		std::deque<int> nums = parse_list(list);
		outputs.push_back(runBAPC(nums, p));
	}

	print_vector(outputs);

	return 0;
}
