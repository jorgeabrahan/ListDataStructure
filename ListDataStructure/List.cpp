#include <iostream>
#include <stack>
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

int List::count(int number) {
	int matches = 0;
	for (Node* current_node = first; current_node != NULL; current_node = current_node->next) {
		if (current_node->data == number) matches++;
	}
	return matches;
}

void List::remove(int index_to_remove) {
	if (index_to_remove >= nodes_amount) return;
	bool is_index_negative = index_to_remove < 0;
	index_to_remove = is_index_negative ? nodes_amount + index_to_remove : index_to_remove;
	if (index_to_remove < 0) return;
	if (index_to_remove == 0) return removeFirst();
	int counter = 0;
	bool is_last_node_being_removed = index_to_remove == (nodes_amount - 1);
	for (Node* current_node = first; current_node != NULL; current_node = current_node->next) {
		if (counter != (index_to_remove - 1)) {
			counter++;
			continue;
		}
		Node* node_to_remove = current_node->next;
		current_node->next = is_last_node_being_removed ? NULL : current_node->next->next;
		if (is_last_node_being_removed) last = current_node;
		delete(node_to_remove);
		nodes_amount--;
		return;
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

void List::showReverse() {
	if (nodes_amount == 0) {
		cout << "list is empty!";
		return;
	}
	stack<int> stack;
	// all nodes are added to a stack
	for (Node* current_node = first; current_node != NULL; current_node = current_node->next) stack.push(current_node->data);
	// nodes are taken out from the stack and displayed
	while (!stack.empty()) {
		cout << stack.top() << ", ";
		stack.pop();
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
