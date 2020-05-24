#include "BinarySearchTree.h"
#include <time.h>

int main()
{
	cout << "\t\t----------------------------------------------------------------" << endl;
	cout << "\t\t----------Example for iterative bypass of binary tree ----------" << endl;
	cout << "\t\t----------------------------------------------------------------" << endl;

	Node node(50); // возьмём за корень
	BinaryTree tree(&node);

	srand(time(0));
	for (int i = 0; i < 10; i++) // для примера добавим к нашему узлу ещё 10
	{
		int number = rand() % 100;
		Node node(number);
		BinaryTree::insertNode(tree.getRoot(), &node);
	}

	cout << " Bypass in direct order" << endl;
	tree.print_direct_order();
	cout << " Bypass in reverse order" << endl;
	tree.print_reverse_order();
	cout << " Bypass in width" << endl;
	tree.print_in_width();

	system("pause");
	return 0;
}