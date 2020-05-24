#include "binTree.h"
#include <stack>

void BinTree::insertauto(Node* root, Node* cpy)
{
	if (root == nullptr)
	{
		root = new Node;
		root->key = cpy->key;
		root->left = root->right = root->data = nullptr;
		return;
	}
	Node* tmp1 = root;
	Node* tmp2 = root;

	while (tmp1 != nullptr)
	{
		tmp2 = tmp1;
		if (cpy->key < tmp1->key)
			tmp1 = tmp1->left;
		else
			tmp1 = tmp1->right;
	}
	if (cpy->key < tmp2->key)
	{
		tmp2->left = new Node();
		tmp2->left->key = cpy->key;
		tmp2->left->data = tmp2;

		tmp2->left->left = nullptr;
		tmp2->left->right = nullptr;
	}
	else
	{
		tmp2->right = new Node();
		tmp2->right->key = cpy->key;
		tmp2->right->data = tmp2;

		tmp2->right->left = nullptr;
		tmp2->right->right = nullptr;
	}
}
void BinTree::it1()
{
	if (root == nullptr)
		return;
	stack<Node*> s;
	s.push(root);
	while (!s.empty())
	{
		Node* tmp = s.top();
		s.pop();
		cout << *tmp << " ";
		if (tmp->gright() != nullptr)
			s.push(tmp->gright());
		if (tmp->gleft() != nullptr)
			s.push(tmp->gleft());
	}
}
	Node* BinTree::getRoot() const { return root; }

/*Node* BinTree::search() {
	if (root == nullptr) throw std::exception("Tree is empty");
	Node* tmp = root;
	while (tmp != nullptr && tmp->key != _key) {
		if (_key < tmp->key) tmp = tmp->left;
		else tmp = tmp->right;
	}
	return tmp;
}*/
/*void BinTree::remove() {
	if (root == nullptr) throw std::exception("Tree is empty");
	Node* tmp = search(_key);
	Node* tmp1 = nullptr;
	Node* tmp2 = nullptr;
	if (tmp->left != nullptr && tmp->right != nullptr)
		tmp2 = search(tmp);
	else
		tmp2 = tmp;
	if (tmp2->left != nullptr)
		tmp1 = tmp2->left;
	else
		tmp1 = tmp2->right;
	if (tmp1 != nullptr) tmp1->data = tmp2->data;
	if (tmp2->data != nullptr) {
		if (tmp2 == tmp2->data->left) tmp2->data->left = tmp1;
		else tmp2->data->right = tmp1;
	}
	if (tmp2 != tmp) {
		tmp->key = tmp2->key;
	}
}
*/