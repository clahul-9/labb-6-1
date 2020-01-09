#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}


bool DoublyLinkedList::add(Node* data, int pos) {
	if ((pos>=0 ||pos<this->search(tail))&&size()>0)
	{
		Node* ptr = head;
		for (int i = 0; i < pos; i++)
		{
			ptr = nodeAt(i)->getNext();
			if (i==pos-1)
			{
				data->setNext(nodeAt(i + 1)->getPrev());
				data->setPrev(nodeAt(i)->getNext());
				ptr->setNext(data->getPrev());
				return true;
			}
		}
	}
	else if(pos==0||pos==size())
	{
		if (size() != 0&&pos==0) {
			data->setNext(head);
			head = data;
			return true;
		}
		else if(size()!=0&&pos==size())
		{
			data->setPrev(tail);
			tail = data;
			return true;
		}
		else if (size()==0)
		{
			head = data;
			tail = data;
			return true;
		}
	}
	return false;
}

bool DoublyLinkedList::remove(int pos){
	if (pos >= 0 || pos <= this->search(tail)) {
		for (int i = 0; i <= pos; i++)
		{
			if (i==pos)
			{
				nodeAt(i - 1)->setNext(nodeAt(i)->getNext());
				nodeAt(i + 1)->setPrev(nodeAt(i)->getPrev());
				nodeAt(i)->~Node();
				return true;
			}
		}
	}
	return false;
}

bool DoublyLinkedList::replace(Node* old, Node* newN) {
	Node* ptr = head;

	for (int i = 0; i < this->size(); i++)
	{
		if (ptr==old)
		{
			old->setData(newN->getData());
			newN->~Node();
			return true;
		}

	}
	return false;
}

int DoublyLinkedList::search(Node* data){
	
	Node* ptr = head;
	for (int i = 0; i <this->size(); i++)
	{
		if (data == ptr )
		{
			return i;
		}
		ptr = ptr->getNext();
	}
}
Node* DoublyLinkedList::nodeAt(int pos) {
	Node* ptr = head;
	for (int i = 0; i <= pos; i++)
	{
		if (i==pos)
		{
			return ptr;
		}
		ptr = ptr->getNext();
	}
}

void DoublyLinkedList::display_forward() {
	Node* ptr = head;

	for (int i = 0; i < this->size(); i++)
	{
		std::cout<<ptr->getData()<< ", ";
		ptr = ptr->getNext();
	}
	std::cout << std::endl;
}
void DoublyLinkedList::display_backwards() {
	Node* ptr = tail;

	for (int i = 0; i < this->size(); i++)
	{
		std::cout << ptr->getData() << ", ";
		ptr = ptr->getPrev();
	}
	std::cout << std::endl;
}

int DoublyLinkedList::size(){
	int nr = 0;
	if (head != nullptr) {
		Node* ptr = head;
		while (ptr != nullptr)
		{
			nr++;
			ptr = ptr->getNext();
		}
	}
	return nr;
}


DoublyLinkedList::~DoublyLinkedList()
{
}
