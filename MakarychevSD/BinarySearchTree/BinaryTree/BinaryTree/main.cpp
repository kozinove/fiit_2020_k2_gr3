#include "TreeNode.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
	TreeNode<float>* root = new TreeNode<float>(12);
	TreeNode<float>* T1 = new TreeNode<float>(5, nullptr, nullptr, nullptr, root);
	TreeNode<float>* T2 = new TreeNode<float>(15, nullptr, nullptr, nullptr, root);
	TreeNode<float>* T3 = new TreeNode<float>(1, nullptr, nullptr, nullptr, T1);
	TreeNode<float>* T4 = new TreeNode<float>(6, nullptr, nullptr, nullptr, T1);
	TreeNode<float>* T5 = new TreeNode<float>(13, nullptr, nullptr, nullptr, T2);
	TreeNode<float>* T6 = new TreeNode<float>(18, nullptr, nullptr, nullptr, T2);
	root->SetLeft(T1);
	root->SetRight(T2);
	T1->SetLeft(T3);
	T1->SetRight(T4);
	T2->SetLeft(T5);
	T2->SetRight(T6);
	BinaryTree<float> B(root);
	cout << *T1 << endl;
	cout << B <<endl;
	B.Remove(T5);
	cout << B << endl;

	TreeNode<float>* T9 = new TreeNode<float>(8);
	B.Insert(T9);
	cout << B << endl;

	cout << *(B.SearchMax());

	return 0;
}