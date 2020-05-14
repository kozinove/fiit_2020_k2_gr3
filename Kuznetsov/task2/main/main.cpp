#include "BinaryTree.h"

int main()
{
	
	Node tree(25);

	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int number = rand() % 50;
		Node node(number);
		Node::insertNode(&tree, &node);
	}

	cout << "Keys of tree: " << tree << endl;

	int n;
	cout << "Enter the number to delete the node: ";
	cin >> n;
	tree.removeNode(Node::searchNode(&tree, n));

	cout << "Keys of tree: " << tree << endl;

	return 0;
}