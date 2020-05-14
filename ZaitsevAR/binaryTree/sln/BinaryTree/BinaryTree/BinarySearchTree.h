#pragma once
#include <iostream>
#include <time.h>

using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
	Node* parent;

	Node();
	Node(int key_); // создадим дерево из "n" рандомных элементов
	~Node();

	Node* searchMin(Node* root); // поиск минимального элемента
	Node* searchNext(Node* curr); // поиск следующего элемента
	static Node* searchNode(Node* root, int key_); // поиск элемента по ключу

	static void insertNode(Node* root, Node* node);
	void removeNode(Node* z);

	static void print(const Node* root);
	friend ostream& operator<<(ostream& out, const Node& root);
};