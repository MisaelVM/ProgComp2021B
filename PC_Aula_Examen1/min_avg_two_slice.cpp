#include <iostream>
#include <vector>

std::vector<int> prefix_sum(std::vector<int>& v) {
	std::vector<int> prefix;
	prefix.reserve((int)v.size() + 1);
	prefix.push_back(0);
	for (auto& i : v)
		prefix.push_back(prefix.back() + i);
	return prefix;
}

int solution(std::vector<int> &A) {
	std::vector<int> p = prefix_sum(A);
	double min_avg = (A[0] + A[1]) / 2.;
	double avg = min_avg;
	int min_i = 0;
	int i = 0;
	int j = 3;
	while (j < (int)p.size()) {
		avg = double(p[j] - p[i]) / double(j - i);
		if (avg > (A[j - 1] + A[j - 2]) / 2.) {
			avg = (A[j - 1] + A[j - 2]) / 2.;
			i = j - 2;
		}

		if (avg < min_avg) {
			min_avg = avg;
			min_i = i;
		}
		++j;
	}
	return min_i;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> nums;
	
	// Caso de prueba
	// Entrada:
	// 4 2 2 5 1 5 8
	// Salida:
	// 1
	//
	nums = { 4, 2, 2, 5, 1, 5, 8 };
	std::cout << solution(nums) << "\n";

	return 0;
}
