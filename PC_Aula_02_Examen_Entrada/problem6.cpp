#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

template <typename T>
class Tree;

template <typename T>
class Node {
	friend class Tree<T>;
private:
	T data;
	Node<T>* left;
	Node<T>* right;

public:
	Node() : data(T()), left(nullptr), right(nullptr) {}
	Node(const T& _data) : data(_data), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree {
private:
	Node<T>* root;

	void recursive_insert(Node<T>*& node, const T& item) {
		if (!node)
			node = new Node<T>(item);
		else if (item == node->data)
			return;
		else if (item < node->data)
			recursive_insert(node->left, item);
		else
			recursive_insert(node->right, item);
	}

	void clear(Node<T>*& node) {
		if (node) {
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}

	void recursive_print(Node<T>* node) const {
		if (node) {
			recursive_print(node->left);
			std::cout << node->data << " ";
			recursive_print(node->right);
		}
	}

	void construct_recursive(const std::vector<int>& v, int l, int r, Node<T>*& node) {
		if (l <= r) {
			int m = l + (r - l) / 2;

			node = new Node<T>(v[m]);
			construct_recursive(v, l, m - 1, node->left);
			construct_recursive(v, m + 1, r, node->right);
		}
	}

public:
	Tree() : root(nullptr) {}
	Tree(const std::vector<int>& v) { construct_recursive(v, 0, (int)v.size() - 1, root); }
	~Tree() { clear(root); }

	void insert(const T& item) {
		recursive_insert(root, item);
	}

	void print() const {
		recursive_print(root);
		std::cout << "\n";
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> values;
	values.reserve(10);
	for (int i = 0; i < 10; ++i)
		values.push_back(rand() % 10);
	std::sort(values.begin(), values.end());
	
	Tree<int> T = values;
	T.print();

	return 0;
}
