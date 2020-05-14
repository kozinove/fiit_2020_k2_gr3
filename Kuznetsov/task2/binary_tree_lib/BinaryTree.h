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
	Node(int key_);
	~Node();

	Node* searchMin(Node* root);
	Node* searchNext(Node* curr);
	static Node* searchNode(Node* root, int key_);

	static void insertNode(Node* root, Node* node);
	void removeNode(Node* z);

	static void print(const Node* root);
	friend ostream& operator<<(ostream& out, const Node& root);
};