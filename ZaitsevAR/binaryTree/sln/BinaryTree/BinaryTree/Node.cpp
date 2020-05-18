#include "Node.h"

Node* Node::getLeft() const { return left; }
Node* Node::getRight() const { return right; }
Node* Node::getParent() const { return parent; }

void Node::setLeft(Node* left_) { left = left_; };
void Node::setRight(Node* right_) { right = right_; };
void Node::setParent(Node* parent_) { parent = parent_; };

Node::Node()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

Node::Node(int key_)
{
	key = key_;
	left = right = parent = nullptr;
}

Node::Node(const Node& node)
{
	key = node.key;
	left = node.left;
	right = node.right;
	parent = node.parent;
}

Node::~Node()
{
	left = nullptr;
	right = nullptr;
}

ostream& operator<<(ostream& out, const Node& root)
{
	out << " " << root.key << "\t";

	return out;
}