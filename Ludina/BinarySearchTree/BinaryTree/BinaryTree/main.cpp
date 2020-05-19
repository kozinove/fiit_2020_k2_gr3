#include "BinaryTree.h"
#include <time.h>

int main()
{

	Node node(50);
	BinaryTree tree(&node);

	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int number = rand() % 100;
		Node node(number);
		BinaryTree::insert(tree.getRoot(), &node);
	}
	cout << "Keys of tree: " << tree << endl;
	int n;
	cout << "Select the number to delete the node: ";
	cin >> n;
	tree.remove(BinaryTree::Search(tree.getRoot(), n));
	cout << "Keys of tree: " << tree << endl;

	system("pause");
	return 0;
}