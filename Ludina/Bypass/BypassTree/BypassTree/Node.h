#pragma once
#include <iostream>

using namespace std;

class Node
{
private:
	int key;
	Node* parent;
	Node* Left;
	Node* Right;
public:
	Node();
	Node(int _key = 0, Node* left = nullptr, Node* right = nullptr) : key(_key), Left(left), Right(right) {}
	Node(const Node& copy);
	~Node();

	Node* getLeft() const;
	Node* getRight() const;
	Node* getParent() const;
	int getkey() const;

	void setLeft(Node* left);
	void setRight(Node* right);
	void setParent(Node* _parent);
	void setkey(int _key);

	friend ostream& operator<<(ostream& out, const Node& root)
	{
		out << " " << root.key;
		return out;
	}
};
