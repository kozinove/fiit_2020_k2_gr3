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
		tree.insert(&node);
	}
	cout << "Keys of tree: " << tree << endl;
	int n;
	cout << "Select the number to delete the node: ";
	cin >> n;
	cout << "Next node: ";
	cout << *(tree.SearchNext(tree.Search(n))) << endl;
	tree.remove(tree.Search(n));
	cout << "Keys of tree after deleting: " << tree << endl;

	system("pause");
	return 0;
}