#include <bits/stdc++.h>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<vvi> vvvi;

constexpr int INF = 1e9;

int nag_dp(const vvi& gallery, int k, int r, int c, vvvi& NAG) {
	if (!k)
		return 0;

	if (r < 0)
		return INF;

	if (NAG[k][r][c] != -1)
		return NAG[k][r][c];

	int tmp = std::min(nag_dp(gallery, k, r - 1, c, NAG), nag_dp(gallery, k, r - 1, c ^ 1, NAG));
	int result = std::min(nag_dp(gallery, k - 1, r - 1, c, NAG) + gallery[r][c], tmp);

	NAG[k][r][c] = result;
	return result;
}

int narrow_art_gallery(const vvi& gallery, int k) {
	int n = gallery.size();
	vvvi NAG(k + 1, vvi(n, vi(2, -1)));
	return std::min(nag_dp(gallery, k, n - 1, 0, NAG), nag_dp(gallery, k, n - 1, 1, NAG));
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, k, u, v;
	std::cin >> N >> k;

	int total = 0;
	vvi gallery(N, vi(2));
	for (int i = 0; i < N; ++i) {
		std::cin >> gallery[i][0] >> gallery[i][1];
		total += (gallery[i][0] + gallery[i][1]);
	}
	
	int tmp1, tmp2;
	std::cin >> tmp1 >> tmp2;
	if (tmp1 || tmp2)
		return 1;

	std::cout << total - narrow_art_gallery(gallery, k) << "\n";

	return 0;
}
