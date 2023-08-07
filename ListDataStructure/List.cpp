#include <iostream>
#include "List.h"
#include "Node.h"

using namespace std;

List::List() {
	nodes_amount = 0;
	first = NULL;
	last = NULL;
}

// add elements at the beginning of the list
void List::prepend(int number) {
	// create node
	Node* node = new(Node);
	// add data to created node
	node->data = number;
	// set node next to the previous created node
	node->next = first;
	// set first to newly created node
	first = node;
	if (nodes_amount == 0) last = node;
	// increment nodes amount
	nodes_amount++;
}

// add elements at the end of the list
void List::append(int number) {
	// create node
	Node* node = new(Node);
	// add data to created node
	node->data = number;
	// if list is empty
	if (nodes_amount == 0) {
		// set first and last list pointers to the newly created node
		first = node;
	}
	else {
		// add the created node to the list
		last->next = node;
	}
	// set last to the created node
	last = node;
	nodes_amount++;
}

void List::remove(int index) {
	// for index <= 0 remove the first one
	if (index <= 0) {
		removeFirst();
		return;
	}
	int counter = 0;
	for (Node* node = first; node != NULL; node = node->next) {
		bool is_one_before_last = counter == (nodes_amount - 2);
		// one position before the desired index
		if (counter == (index - 1)) {
			Node* remove = node->next;
			// if user wants to remove last node
			if (index == (nodes_amount - 1)) {
				node->next = NULL;
				last = node;
			} else node->next = node->next->next;
			nodes_amount--;
			delete(remove);
			return;
		}
		if (is_one_before_last && index > (nodes_amount - 1)) {
			Node* remove = node->next;
			node->next = NULL;
			last = node;
			nodes_amount--;
			delete(remove);
			return;
		}
		counter++;
	}
}

void List::removeFirst() {
	if (nodes_amount == 0) return;

	if (nodes_amount == 1) {
		delete(first);
		first = last = NULL;
	}
	else {
		Node* node = first;
		first = first->next;
		delete(node);
	}
	nodes_amount--; // always decrease amount
}

void List::clear() {
	while (nodes_amount > 0) removeFirst();
}

void List::show() {
	if (nodes_amount == 0) {
		cout << "list is empty!";
		return;
	}
	for (Node* node = first; node != NULL; node = node->next) {
		cout << node->data << ", ";
	}
	cout << endl;
}

int List::findIndex(int number) {
	if (nodes_amount == 0) return -1;
	int counter = 0;
	for (Node* node = first; node != NULL; node = node->next) {
		if (node->data == number) return counter; // number found
		counter++;
	}
	return -1; // nothing found
}

// inserts a number in an index
void List::insert(int index, int number) {
	// for index <= 0 insert the number at the beginning
	if (index <= 0) {
		prepend(number);
		return;
	}
	// for index >= list_length insert the number at the end
	if (index > (nodes_amount - 1)) {
		append(number);
		return;
	}

	int counter = 0;
	for (Node* node = first; node != NULL; node = node->next) {
		// one position before the desired index
		if (counter == (index - 1)) {
			Node* new_node = new(Node);
			new_node->data = number;

			Node* temporal = node->next;
			node->next = new_node;
			new_node->next = temporal;
			nodes_amount++;
			return;
		}
		counter++;
	}
}


// print a list using cout syntax
ostream& operator<<(ostream& output, List list) {
	list.show();
	return output;
}
