// Starts with N (1 <= N <= 1,000,000, N odd) empty stacks, Bessie is
// given a sequence of K instructions (1 <= K <= 25,000), each of the
// form "A B", meaning that Bessie should add one new haybale to the
// top of each stack in the range A..B.
// Compute the median height afterwards

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K, l, r;
	std::cin >> N >> K;

	std::vector<int> A(N, 0);
	std::vector<int> D(N + 1, 0);

	for (int i = 0; i < K; ++i) {
		std::cin >> l >> r;
		++D[l];
		--D[r + 1];
	}

	A[0] = D[0];
	for (int i = 1; i < N; ++i)
		A[i] = D[i] + A[i - 1];
	sort(A.begin(), A.end());

	std::cout << A[(int)ceil(A.size() / 2)] << "\n";

	return 0;
}
