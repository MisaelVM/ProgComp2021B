#include <bits/stdc++.h>

int max_continuous_sum(std::vector<int>& string) {
	int total_sum = string[0];

	int max_sum = string[0];
	int local_max_sum = string[0];

	int min_sum = string[0];
	int local_min_sum = string[0];

	// Kadane para hallar suma maxima y minima
	for (int i = 1; i < (int)string.size(); ++i) {
		total_sum += string[i];

		local_max_sum = (string[i] > local_max_sum + string[i]) ? string[i] : local_max_sum + string[i];
		if (max_sum < local_max_sum)
			max_sum = local_max_sum;

		local_min_sum = (string[i] < local_min_sum + string[i]) ? string[i] : local_min_sum + string[i];
		if (min_sum > local_min_sum)
			min_sum = local_min_sum;
	}
	
	// El complemento de la suma minima resulta en un maximo local que da vuelta (circular) a la cuerda
	int min_sum_complement = total_sum - min_sum;
	// Devolver maximo global
	return std::max(max_sum, min_sum_complement);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int M, MI;
	while (std::cin >> M) {
		std::vector<int> string;
		string.reserve(M * 10);
		for (int i = 0; i < M * 10; ++i) {
			std::cin >> MI;
			string.push_back(MI);
		}
		std::cout << max_continuous_sum(string) << "\n";
	}

	return 0;
}
