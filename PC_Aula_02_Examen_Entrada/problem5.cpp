#include <iostream>
#include <cmath>
#include <cstdlib>

template <typename T>
class Tree;

template <typename T>
class Node {
	friend class Tree<T>;
private:
	T data;
	int height;
	Node<T>* left;
	Node<T>* right;

public:
	Node() : data(T()), height(0), left(nullptr), right(nullptr) {}
	Node(const T& _data) : data(_data), height(0), left(nullptr), right(nullptr) {}
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
		update(node);
	}

	void clear(Node<T>*& node) {
		if (node) {
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}

	void update(Node<T> *node) {
		int leftNodeHeight = (node->left) ? node->left->height : -1;
		int rightNodeHeight = (node->right) ? node->right->height : -1;
		node->height = (leftNodeHeight < rightNodeHeight) ? rightNodeHeight + 1 : leftNodeHeight + 1;
	}

	void recursive_print(Node<T>* node) const {
		if (node) {
			recursive_print(node->left);
			std::cout << "Data: " << node->data << ", Height: " << node->height << ", Balanced: " << check_balance(node) << "\n";
			recursive_print(node->right);
		}
	}

public:
	Tree() : root(nullptr) {}
	~Tree() { clear(root); }

	void insert(const T& item) {
		recursive_insert(root, item);
	}

	bool check_balance(Node<T>* node) const {
		int leftNodeHeight = (node->left) ? node->left->height : -1;
		int rightNodeHeight = (node->right) ? node->right->height : -1;
		return abs(leftNodeHeight - rightNodeHeight) <= 1;
	}

	void print() const {
		recursive_print(root);
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	Tree<int> T;

	srand(time(nullptr));

	for (int i = 0; i < 10; ++i)
		T.insert(rand() % 100);
	T.print();

	return 0;
}
