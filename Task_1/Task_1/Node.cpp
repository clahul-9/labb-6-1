#include "Node.h"



Node::Node(int data, Node* next,Node* prev)
{
	setData(data);
	setNext(next);
	setPrev(prev);
}
Node::Node(int data) {
	setData(data);
}

int Node::getData() { return data; }
void Node::setData(int dataIn) { data = dataIn; }

Node* Node::getNext() { return next; }
void Node::setNext(Node* nextIn) { next = nextIn; }

Node* Node::getPrev() { return prev; }
void Node::setPrev(Node* prevIn) { prev = prevIn; }

Node::~Node()
{
}
