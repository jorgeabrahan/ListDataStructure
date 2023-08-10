#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List list;
	list.append(5);
	list.append(3);
	list.append(6);
	list.append(5);
	list.append(7);
	list.append(2);
	list.append(9);

	cout << endl;
	cout << "List show()" << endl;
	list.show();
	cout << "List showReverse()" << endl;
	list.showReverse();
	cout << endl;
	list.clear();
	list.show(); // list is empty!
}
