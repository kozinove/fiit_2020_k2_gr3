#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	int key;
	Node* parent;
	Node* Left;
	Node* Right;

	Node();
	Node(int _key);
	~Node();

	void remove(Node* z);//удаление вершины
	Node* SearchNext(Node* curr);
	Node* SearchMin(Node* root);
	static Node* Search(Node* root, int _key);
	static void insert(Node* root, Node* node);

	static void print(const Node* root);
	friend ostream& operator<<(ostream& out, const Node& root);
};