#include "binary.h"

Node::Node()
{
	left = nullptr;
	right = nullptr;
	data = nullptr;
}
Node::Node(const Node& cpy)
{
	key = cpy.key;
	left = cpy.left;
	right = cpy.right;
	data = cpy.data;
}

Node::Node(int _key) {
	key = _key;
	left = nullptr;
	right = nullptr;
	data = nullptr;
}

Node::~Node()
{
	left = nullptr;
	right = nullptr;
	data = nullptr;
}

Node* Node::gleft() const { return left; }
Node* Node::gright() const { return right; }
Node* Node::gdata() const { return data; }

void Node::setleft(Node* lpod) { left = lpod; }
void Node::setright(Node* rpod) { right = rpod; }
void Node::setdata(Node* dData) { data = dData; }

ostream& operator<<(ostream& out, const Node& root)
{
	out << " " << root.key;
	return out;
}