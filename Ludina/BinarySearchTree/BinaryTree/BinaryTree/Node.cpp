#include "Node.h"

Node::Node()
{
	key = 0;
	parent = nullptr;
	Left = nullptr;
	Right = nullptr;
}

Node::Node(int _key)
{
	key = _key;
	parent = nullptr;
	Left = nullptr;
	Right = nullptr;
}

Node::~Node()
{
	key = 0;
	parent = nullptr;
	Left = nullptr;
	Right = nullptr;
};

Node::Node(const Node& copy)
{
	key = copy.key;
	parent = copy.parent;
	Left = copy.Left;
	Right = copy.Right;
}

Node* Node::getLeft() const { return Left; }
Node* Node::getRight() const { return Right; }
Node* Node::getParent() const { return parent; }
int Node::getkey() const { return key; }

void Node::setLeft(Node* left) { Left = left; }
void Node::setRight(Node* right) { Right = right; }
void Node::setParent(Node* _parent) { parent = _parent; }
void Node::setkey(int _key) { key = _key; }