#include "BinarySearchTree.h"
#include <time.h>

int main()
{
	cout << "\t\t-----------------------------------------------" << endl;
	cout << "\t\t----------Example for deleting a node----------" << endl;
	cout << "\t\t-----------------------------------------------" << endl;

	Node node(50); // возьмём за корень
	BinaryTree tree(&node);

	srand(time(0));
	for (int i = 0; i < 10; i++) // для примера добавим к нашему узлу ещё 10
	{
		int number = rand() % 100;
		Node node(number);
		BinaryTree::insertNode(tree.getRoot(), &node);
	}

	cout << " Keys of your tree:\n" << tree << endl << endl;

	int n;
	cout << " Enter one of the following numbers to delete the node with this key: ";
	cin >> n;
	tree.removeNode(BinaryTree::searchNode(tree.getRoot(), n));

	cout << " Keys of your tree:\n" << tree << endl << endl;

	system("pause");
	return 0;
}