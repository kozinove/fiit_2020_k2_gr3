#include "TreeNode.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
	TreeNode<float>* root = new TreeNode<float>(1);
	TreeNode<float>* T1 = new TreeNode<float>(2, nullptr, nullptr, nullptr, root);
	TreeNode<float>* T2 = new TreeNode<float>(3, nullptr, nullptr, nullptr, root);
	TreeNode<float>* T3 = new TreeNode<float>(4, nullptr, nullptr, nullptr, T1);
	TreeNode<float>* T4 = new TreeNode<float>(5, nullptr, nullptr, nullptr, T1);
	TreeNode<float>* T5 = new TreeNode<float>(6, nullptr, nullptr, nullptr, T2);
	TreeNode<float>* T6 = new TreeNode<float>(7, nullptr, nullptr, nullptr, T2);
	root->SetLeft(T1);
	root->SetRight(T1);
	T1->SetLeft(T3);
	T1->SetRight(T4);
	T2->SetLeft(T5);
	T2->SetRight(T6);
	BinaryTree<float> B(root);
	cout << *T1;


	return 0;
}