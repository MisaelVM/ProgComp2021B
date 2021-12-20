#include <bits/stdc++.h>

double max_torque(double a, double b, double c) {
	double x = b / (2. * a);
	return -a * x * x + b * x + c;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int TC, n, a, b, c;
	std::cin >> TC;
	for (int i = 0; i < TC; ++i) {
		std::cin >> n;
		int max_gear = 0;
		double max_gear_torque = INT_MIN;
		for (int j = 0; j < n; ++j) {
			std::cin >> a >> b >> c;
			double gear_torque = max_torque(a, b, c);
			if (gear_torque > max_gear_torque) {
				max_gear_torque = gear_torque;
				max_gear = j + 1;
			}
		}
		std::cout << max_gear << "\n";
	}

	return 0;
}
