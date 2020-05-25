#include "binTree.h"
#include <time.h>

int main()
{
	int n = 0;
	/*int q = 0;
	cout << "1 - auto, 2 - manually" << endl;
	cin >> q;
	switch (q)
	{
	case 1:
	{*/
		Node cpy(1);
		BinTree bt(&cpy);
		cout << "Vershin" << endl;
		cin >> n;
		srand(time(0));
		for (int i = 0; i < n; i++)
		{
			int versh = rand() % 100;
			Node cpy(versh);
			BinTree::insertauto(bt.getRoot(), &cpy);
		}
		cout << " Bypass" << endl;
		bt.it1();
		system("pause");
		return 0;
	}
	/*case 2:
	{
		int t1, t2;
		cout << "enter root" << endl;
		cin >> t1;

		cout << "Vershin" << endl;
		cin >> n;
		for (int j = 0; j < n; j++)
		{ }
	}
	}*/
