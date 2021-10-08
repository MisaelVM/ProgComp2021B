#include <iostream>
#include <vector>
#include <algorithm>

void build_segment_tree(const std::vector<long long>& nums, std::vector<long long>& seg_tree, int tree_index, int low, int high) {
	if (low == high)
		seg_tree[tree_index] = nums[low];
	else {
		int mid = (low + high) / 2;
		build_segment_tree(nums, seg_tree, 2 * tree_index + 1, low, mid);
		build_segment_tree(nums, seg_tree, 2 * tree_index + 2, mid + 1, high);
		seg_tree[tree_index] = seg_tree[2 * tree_index + 1] + seg_tree[2 * tree_index + 2];
	}
}

long long seg_tree_query(const std::vector<long long>& seg_tree, int tree_index, int low, int high, int a, int b) {
	if (low >= a && high <= b)
		return seg_tree[tree_index];

	if (high < a || low > b)
		return 0;

	int mid = (low + high) / 2;
	long long left = seg_tree_query(seg_tree, 2 * tree_index + 1, low, mid, a, b);
	long long right = seg_tree_query(seg_tree, 2 * tree_index + 2, mid + 1, high, a, b);
	return left + right;
}

void update_seg_tree(std::vector<long long>& seg_tree, int tree_index, int low, int high, int k, long long u) {
	if (low == high)
		seg_tree[tree_index] = u;
	else {
		int mid = (low + high) / 2;
		if (k <= mid && k >= low)
			update_seg_tree(seg_tree, 2 * tree_index + 1, low, mid, k, u);
		else
			update_seg_tree(seg_tree, 2 * tree_index + 2, mid + 1, high, k, u);
		seg_tree[tree_index] = seg_tree[2 * tree_index + 1] + seg_tree[2 * tree_index + 2];
	}
}

void update(std::vector<long long>& seg_tree, int n, int k, long long u) {
	update_seg_tree(seg_tree, 0, 0, n - 1, k - 1, u);
}

long long query(const std::vector<long long>& seg_tree, int n, int a, int b) {
	return seg_tree_query(seg_tree, 0, 0, n - 1, a - 1, b - 1);
}

void print_vector(const std::vector<long long>& v) {
	for (auto& i : v)
		std::cout << i << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<long long> nums, seg_tree, queries;
	int n, q;
	long long x;
	std::cin >> n >> q;
	nums.reserve(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		nums.push_back(x);
	}
	seg_tree.resize(4 * n, 0);
	build_segment_tree(nums, seg_tree, 0, 0, n - 1);
	
	int op, a, b;
	for (int i = 0; i < q; ++i) {
		std::cin >> op >> a >> b;
		if (op == 1)
			update(seg_tree, n, a, b);
		else if (op == 2)
			queries.push_back(query(seg_tree, n, a, b));
	}

	print_vector(queries);

	return 0;
}
