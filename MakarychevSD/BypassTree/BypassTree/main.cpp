#include "TreeNode.h"
#include "BinaryTree.h"
#include "Iterator.h"

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

	B.BypassInOrder();
	cout << endl << endl;

	B.BypassInWidth();
	cout << endl << endl;

	B.BypassLTR();
	cout << endl << endl;

	Iterator<float> i(root);
	while (i.hasNext())
	{
		cout << i.Next() << " ";
	}
	cout << endl;

	return 0;
}