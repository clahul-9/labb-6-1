#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>


void add(DoublyLinkedList list, Node node, int pos) {

	
	if (list.add(&node, pos) == 1)
	{ list.display_forward(); }
	else if (list.add(&node, pos) == 0)
	{
		std::cout << "Error: Node could not be added" << std::endl;
	}
	else { std::cout << "Error: Something went wrong" << std::endl; }
}
void remove(DoublyLinkedList list, int pos) {
	if (list.remove(pos) == 0) { std::cout << "Error: Node at " << pos << " could not be removed" << std::endl; }
	else if (list.remove(pos) == 1) { list.display_forward(); }
	else { std::cout << "Error: Something went wrong" << std::endl; }
}


int main() {
	Node n1(2);
	Node n2(4);
	Node n3(8);

	DoublyLinkedList lista;
	
	add(lista, n1, 0);
	add(lista, n2, 0);


	//remove(lista, 0);


	system("pause");
	Node* ptr = nullptr;
	for (int i = 0; i < lista.size(); i++)
	{
		ptr = lista.nodeAt(i);
		ptr->~Node();
	}
	lista.~DoublyLinkedList();
}

