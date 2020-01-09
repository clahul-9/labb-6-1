#pragma once
#include"Node.h"
class DoublyLinkedList
{
	Node* head;
	Node* tail;
public:
	DoublyLinkedList();

	bool add(Node* data, int pos);
	bool remove(int pos);
	bool replace(Node* old, Node* newN);
	int search(Node*data);
	Node* nodeAt(int pos);
	void display_forward();
	void display_backwards();
	int size();
	~DoublyLinkedList();
};

