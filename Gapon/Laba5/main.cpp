#include <iostream>
#include <string>
#include "Stack.h"
#include <windows.h>
using namespace std;

struct Node
{
	string key;
	Node* l;
	Node* r;

	Node(string _key = 0, Node* _l = NULL, Node* _r = NULL)
		:key(_key), l(_l), r(_r)
	{}
};


void print(Node* curr)     // Рекурсия TLR
{
	if (curr == NULL) return;
	cout << curr->key << " ";
	print(curr->l);
	print(curr->r);
}

void printItr(Node* root)  // Итерационный TLR
{
	Stack<Node*>st;
	st.Push(root);
	while (!st.IsEmpty())
	{
		Node* curr = st.Top();
		st.Pop();
		cout << curr->key << " ";
		if (curr->r != NULL)
			st.Push(curr->r);
		if (curr->l != NULL)
			st.Push(curr->l);
	}
}

void deleteTree(Node* curr);

class Navigator                          // Навигатор
{
	Node* curr;
	Stack<Node*>path;
public:
	Navigator(Node* root)
	{
		curr = root;
	}

	Node* getCurr() { return curr; }       // Получить текущее значение 

	string& value()
	{
		return curr->key;
	}


	bool left()                           // Налево
	{
		if (curr->l == NULL) return false;
		path.Push(curr);
		curr = curr->l;
		return true;
	}
	bool right()                          // Направо
	{
		if (curr->r == NULL) throw "curr->r == NULL";
		path.Push(curr);
		curr = curr->r;
		return true;
	}
	bool up()                             // Вверх
	{
		if (path.IsEmpty())
		{
			throw "path.IsEmpty()";
		}
		curr = path.Top();
		path.Pop();
		return true;
	}

	void addRigth(string v)                // Добавить справа
	{
		Node* p = new Node(v, curr->r, NULL);
		curr->r = p;
	}

	void addLeft(string v)                 // Добавить слева
	{
		Node* p = new Node(v, curr->l, NULL);
		curr->l = p;
	}

	void deleteR()                         // Удалить
	{
		deleteTree(curr->r);
		curr->r = NULL;
	}
};



void printText(Node* curr, int level, Node* sel)
{
	if (curr == NULL) return;
	if (curr == sel)cout << "*";
	else cout << " ";
	for (int i = 0; i < level; i++)
	{
		cout << "  ";
	}
	cout << curr->key << "\n";
	printText(curr->r, level + 1, sel);
	printText(curr->l, level, sel);
}

void deleteTree(Node* curr)
{
	if (curr == NULL) return;
	deleteTree(curr->l);
	deleteTree(curr->r);
	delete curr;
}

int main()
{

	//setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Node* p1 = new Node("Текст 1");
	Node* p2 = new Node("Текст 2");
	Node* p3 = new Node("Текст 3");
	Node* p4 = new Node("Текст 4", NULL, p1);
	Node* p5 = new Node("Текст 5", p2, p4);
	Node* p6 = new Node("Текст 6", p5, p3);
	Node* root = p6;

	Navigator n(root);

	bool f = true;
	int op;
	while (true)
	{
		system("cls");
		cout << "Успешноть операции " << f << endl;
		cout << "Строка, на которой вы находитесь помечена звездочкой" << endl;
		printText(root, 0, n.getCurr());
		cout << "value " << n.value() << endl;
		cout << "1) Налево \n";
		cout << "2) Направо \n";
		cout << "3) Наверх \n";
		cout << "4) Установить значение \n";
		cout << "5) Добавить справа \n";
		cout << "6) Добавить слева \n";
		cout << "7) Удалить справа \n";

		cin >> op;

		try
		{
			if (op == 1) f = n.left();
			if (op == 2) f = n.right();
			if (op == 3) f = n.up();
			if (op == 4)
			{
				string v;
				cin.ignore();
				getline(cin, v);
				//cin >> v;
				n.value() = v;
			}
			if (op == 5)                  // Устанавливаем значение справа
			{
				string v;
				cout << "Enter value:";
				cin >> v;
				n.addRigth(v);
			}
			if (op == 6)                  // Устанавливаем значение слева
			{
				string v;
				cout << "Enter value:";
				cin >> v;
				n.addLeft(v);
			}

			if (op == 7) n.deleteR();     // Удаляем значение справа

		}
		catch (const char* str)
		{
			cout << str << endl;
			f = false;
		}

	}




	/*print(root); // Рекурсия TLR
	cout << "\n";

	printItr(root);
	cout << "\n";*/

	return 0;
}