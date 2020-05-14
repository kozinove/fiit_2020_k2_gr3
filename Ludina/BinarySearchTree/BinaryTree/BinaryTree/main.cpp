#include "Node.h"
#include <time.h>

int main()
{

	Node tree(50);

	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int number = rand() % 100;
		Node node(number);
		Node::insert(&tree, &node);
	}
	cout << "Keys of tree: " << tree << endl;

	int n;
	cout << "Select the number to delete the node: ";
	cin >> n;
	tree.remove(Node::Search(&tree, n));
	cout << "Keys of tree: " << tree << endl;
	system("pause");
	return 0;
}