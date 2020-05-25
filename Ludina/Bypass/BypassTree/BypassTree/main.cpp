#include "BinaryTree.h"
#include "Iterat.h"

int main()
{
	Node* a1 = new Node(1);
	Node* a2 = new Node(5);
	Node* a3 = new Node(7);
	Node* a4 = new Node(9);

	Node* a5 = new Node(8, a3, a4);
	Node* a6 = new Node(0, nullptr, a1);
	Node* a7 = new Node(4, nullptr, a2);
	Node* a8 = new Node(2, a6, a7);
	Node* a9 = new Node(6, a8, a5);
	Node* a = a9;
	BinaryTree tree(a);

	cout << "Bypass in direct order: " << endl;
	tree.print_itr();
	cout << endl;

	cout << "Iterator: " << endl;
	Iterat i(a);
	while (i.HasNext())
	{
		cout << i.Next() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}