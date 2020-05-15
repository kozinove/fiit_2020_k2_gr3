#include "BinarySearchTree.h"


Node* BinaryTree::searchMin(Node* root)
{
	Node* curr = root;
	while (curr->left != nullptr)
		curr = curr->left;
	return curr;
}

Node* BinaryTree::searchNext(Node* curr)
{
	// следующим ключом будет минимальный в правой ветке
	Node* res = nullptr;

	if (curr->right != nullptr)
	{
		res = searchMin(curr->right);
		return res;
	}
	// но если правой ветки нет, то нужно вернутся к родителю
	res = curr->parent;
	Node* tmp = curr;
	while (res != nullptr && tmp == res->right)
	{
		tmp = res;
		res = res->parent;
	}
	return res;
}

Node* BinaryTree::searchNode(Node* root, int key_)
{
	if (root == nullptr)
		return NULL;
	if (root->key == key_)
		return root;
	if (key_ < root->key)
		return searchNode(root->left, key_);
	else
		return searchNode(root->right, key_);
}

void BinaryTree::insertNode(Node* root, Node* node)
{
	if (root == nullptr)
	{
		root->key = node->key;
		root->left = root->right = root->parent = nullptr;
		return;
	}
	Node* x = root;
	Node* y = x; // для parent

	while (x != nullptr)
	{
		y = x;
		if (node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	if (node->key < y->key)
	{
		y->left = new Node();
		y->left->key = node->key;
		y->left->parent = y;

		y->left->left = nullptr;
		y->left->right = nullptr;
	}
	else
	{
		y->right = new Node();
		y->right->key = node->key;
		y->right->parent = y;

		y->right->left = nullptr;
		y->right->right = nullptr;
	}
}

void BinaryTree::removeNode(Node* z)
{
	// 1) в случае, если удаляемый узел это лист
	if (z->left == nullptr && z->right == nullptr)
	{
		if (z->parent != nullptr)
		{
			if (z == z->parent->left)
				z->parent->left = nullptr;
			else
				z->parent->right = nullptr;
		}
		else
			z = nullptr;
	}
	// 2) в случае, если у удаляемого узла есть 1 потомок
	else if ((z->left == nullptr && z->right != nullptr) ||
		(z->left != nullptr && z->right == nullptr))
	{
		if (z->left == nullptr) // если нет левого, то работаем с правым
		{
			z->right->parent = z->parent;
			if (z->parent->left == z)
				z->parent->left = z->right;
			else
				z->parent->right = z->right;
		}
		else if (z->right == nullptr)
		{
			z->left->parent = z->parent;
			if (z->parent->left == z)
				z->parent->left = z->left;
			else
				z->parent->right = z->left;
		}
		z = nullptr;
	}
	// 3) в случае, если у удаляемого узла есть 2 потомка
	else
	{
		Node* y = nullptr;

		y = searchNext(z);
		z->key = y->key;

		removeNode(y); // с помощью рекурсии сведём к ситуации с 0 и 1 потомком
	}
}

Node* BinaryTree::getRoot() const { return root; }

void BinaryTree::print(const Node* root) // симметричный обход
{
	if (root != nullptr)
	{
		print(root->left);
		cout << *root;
		print(root->right);
	}
}

ostream& operator<<(ostream& out, const BinaryTree& tree)
{
	if (tree.root != nullptr)
		BinaryTree::print(tree.root);

	return out;
}