#include <iostream>
class List;

using namespace std;

class Node {
private:
	int data;
	Node* next;
	Node();

	friend List;
	friend ostream& operator<<(ostream&, List);
};
