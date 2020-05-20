#include "BinTree.h"
#include<iostream>
#include <time.h>

using namespace std;

int main()
{
	int a;
	Node nd(50);
	BinTree tr(&nd)
	srand(time(0));
	int k;
	cout << "enter a number of keys(from 1 to 50): " << endl;
	cin >>k;
	for (int i = 0; i < k - 1; i++) 
	{
		int tmp = rand() % 100;
		Node nd(tmp);
		BinTree::insertNode(tr.getRoot(), &nd);
	}
	cout << "tree keys:" << tr << endl;
	cout << "which key is deleted ";
	cin >> a;
	tr.deleteNode(Node::searchNode(tr.getRoot(), a));
	cout << "keys after deleting: " << tr << endl;
	system("pause");
	return 0;
}
