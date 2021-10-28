#include <iostream>
#include <list>
#include <vector>
#include <queue>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void push_back(ListNode*& node, int val) {
	ListNode* newNode = new ListNode(val);
	if (node) node->next = newNode;
	node = newNode;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
	auto comp = [](ListNode* left, ListNode* right) { return left->val > right->val; };
	std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> pq(comp);

	for (auto& list : lists)
		if (list)
			pq.push(list);

	if (pq.empty())
		return nullptr;
		
	ListNode* initValue = pq.top();
	ListNode* mergedLists = new ListNode(initValue->val);
	ListNode* mergedListsPtr = mergedLists;
	pq.pop();
	if (initValue->next) pq.push(initValue->next);

	while (!pq.empty()) {
		ListNode* nodePtr = pq.top();
		pq.pop();
		push_back(mergedListsPtr, nodePtr->val);
		nodePtr = nodePtr->next;
		if (nodePtr) pq.push(nodePtr);
	}

	return mergedLists;
}

void print_list(ListNode* l) {
	while (l) {
		std::cout << l->val << " ";
		l = l->next;
	}
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ListNode* a3 = new ListNode(5);
	ListNode* a2 = new ListNode(4, a3);
	ListNode* a1 = new ListNode(1, a2);

	ListNode* b3 = new ListNode(4);
	ListNode* b2 = new ListNode(3, b3);
	ListNode* b1 = new ListNode(1, b2);

	ListNode* c2 = new ListNode(6);
	ListNode* c1 = new ListNode(2, c2);

	// Caso de prueba:
	// Entrada:
	// [[1,4,5],[1,3,4],[2,6]]
	// Salida:
	// [1,1,2,3,4,4,5,6]
	//
	std::vector<ListNode*> lists = { a1, b1, c1 };
	ListNode* mergedLists = mergeKLists(lists);
	print_list(mergedLists);

	return 0;
}
