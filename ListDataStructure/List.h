#include <iostream>
class Node;

using namespace std;

class List {
private:
	int nodes_amount;
	// first and last node pointers from the list
	Node* first, * last;
public:
	List();
	void prepend(int number); // LIFO (Last In First Out)
	void append(int number); // FIFO (First In First Out)
	int count(int number);
	void remove(int index);
	void removeFirst();
	void show();
	void showReverse();
	void clear();
	int findIndex(int number);
	void insert(int index, int number);

	friend ostream& operator<<(ostream&, List);
};

