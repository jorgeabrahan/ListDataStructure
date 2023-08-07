#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List list;
	list.append(5);
	list.append(3);
	list.append(7);

	list.prepend(2);

	cout << list.findIndex(3) << endl; // index: 2
	list.show(); // [2, 5, 3, 7]

	list.insert(2, 6);
	cout << list; // [2, 5, 6, 3, 7]

	list.insert(0, 4);
	cout << list; // [4, 2, 5, 6, 3, 7]

	list.insert(5, 10);
	cout << list; // [4, 2, 5, 6, 3, 10, 7]

	list.insert(7, 1);
	cout << list; // [4, 2, 5, 6, 3, 10, 7, 1]

	list.removeFirst();
	cout << list; // [2, 5, 6, 3, 10, 7, 1]

	list.insert(7, 4);
	cout << list; // [2, 5, 6, 3, 10, 7, 1, 4]

	list.append(8);
	cout << list; // [2, 5, 6, 3, 10, 7, 1, 4, 8]

	list.remove(3);
	cout << list; // [2, 5, 6, 10, 7, 1, 4, 8]

	list.remove(2);
	cout << list; // [2, 5, 10, 7, 1, 4, 8]

	list.remove(6);
	cout << list; // [2, 5, 10, 7, 1, 4] -> 4 should be last node

	list.append(3);
	cout << list; // [2, 5, 10, 7, 1, 4, 3] -> 3 should be last node

	list.remove(10);
	cout << list; // [2, 5, 10, 7, 1, 4]

	list.remove(10);
	cout << list; // [2, 5, 10, 7, 1]

	list.remove(10);
	cout << list; // [2, 5, 10, 7]

	list.append(1);
	cout << list; // [2, 5, 10, 7, 1]

	list.clear();

	list.show(); // list is empty!
}
