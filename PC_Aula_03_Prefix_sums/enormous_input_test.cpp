//#include <bits/stdc++>
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k, t, count = 0;
	std::cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		std::cin >> t;
		if (!(t % k))
			++count;
	}

	std::cout << count << "\n";
	
	return 0;
}
