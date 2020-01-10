#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}


bool DoublyLinkedList::add(Node* data, int pos) {

	if (pos>0 && pos<size())
	{
		data->setNext(nodeAt(pos));
		nodeAt(pos - 1)->setNext(data);

		nodeAt(pos + 1)->setPrev(data);
		data->setPrev(nodeAt(pos - 1));
		return true;
	}
	else if(pos==0||pos==size())
	{
		if (size() != 0&&pos==0) {
			data->setNext(nodeAt(pos));
			//std::cout<<"data:" <<data->getData()<<" nAt:"<< nodeAt(pos)->getData() << "\n";
			nodeAt(pos+1)->setPrev(data);
			
			head = data;
			return true;
		}
		else if(size()!=0&&pos==size())
		{
			nodeAt(pos)->setNext(data);
			data->setPrev(nodeAt(pos-1));

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
	if (size() > 0)
	{
		if (pos>0 && pos<size())
		{
			nodeAt(pos - 1)->setNext(nodeAt(pos+1));
			nodeAt(pos + 1)->setPrev(nodeAt(pos - 1));
			nodeAt(pos)->~Node();
			return true;
		}
		else if (pos == 0 )
		{
			head = nodeAt(pos+1);
			nodeAt(pos + 1)->setPrev(nullptr);
			nodeAt(pos)->~Node();
			return true;
		}
		else if (pos==size())
		{
			tail = nodeAt(pos - 1);
			nodeAt(pos - 1)->setNext(nullptr);
			nodeAt(pos)->~Node();
			return true;
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
	//return nullptr;
}

void DoublyLinkedList::display_forward() {
	Node* ptr = head;

	for (int i = 0; i <= size(); i++)
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
		while (ptr != tail)
		{
			nr++;
			ptr = ptr->getNext();
		}
		return nr + 1;
	}
	return 0;
}


DoublyLinkedList::~DoublyLinkedList()
{
}
