#include "binTree.h"
#include"itr.h"
#include <time.h>
#include<iostream>

using namespace std;

int main()
{
	treenode* n1 = new treenode(4);
	treenode* n2 = new treenode(6);
	treenode* n3 = new treenode(7);
	treenode* n4 = new treenode(5);
	treenode* n5 = new treenode(3, n3, n4);
	treenode* n6 = new treenode(2, n1, n2);
	treenode* n7 = new treenode(1, n5, n6);
	treenode* n = n7;
	binTree tree(n);

	cout << "width woraround: " << endl;
	tree.workaround();

	cout << endl << "iterator: " << endl;
	Itr a(n);
	while (a.hasNext()) { cout << a.next() << " "; }

	system("pause");
	return 0;
}