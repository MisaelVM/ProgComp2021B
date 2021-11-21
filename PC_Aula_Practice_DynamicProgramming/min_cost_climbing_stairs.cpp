#include <bits/stdc++.h>

int minCostClimbingStairs_memoized(std::vector<int>& cost, int step, std::vector<int>& memo) {
	if (memo[step])
		return memo[step];
	
	int result;
	if (step <= 1)
		result = cost[step];
	else
		result = cost[step] + std::min(minCostClimbingStairs_memoized(cost, step - 1, memo), minCostClimbingStairs_memoized(cost, step - 2, memo));

	memo[step] = result;
	return result;
}

int minCostClimbingStairs(std::vector<int>& cost) {
	cost.push_back(0);
	std::vector<int> memo(cost.size(), 0);
	return minCostClimbingStairs_memoized(cost, cost.size() - 1, memo);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> cost;
	// Caso de prueba 1:
	// Entrada:
	// cost = [10,15,20]
	// Salida:
	// 15
	cost = { 10, 15, 20 };
	std::cout << minCostClimbingStairs(cost) << "\n";

	// Caso de prueba 2:
	// Entrada:
	// cost = [1,100,1,1,1,100,1,1,100,1]
	// Salida:
	// 6
	cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	std::cout << minCostClimbingStairs(cost) << "\n";

	return 0;
}
