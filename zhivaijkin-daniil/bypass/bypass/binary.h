#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
	Node *data;

	Node();
	Node(const Node& cpy);
	~Node();
	Node(int _key);

	Node* gleft() const;
	Node* gright() const;
	Node* gdata() const;

	void setleft(Node* lpod);
	void setright(Node* rpod);
	void setdata(Node* dData);

	friend ostream& operator<<(ostream& out, const Node& root);
};