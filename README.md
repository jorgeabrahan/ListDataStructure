# ListDataStructure

Simple list data structure project practice. Each node of the list consist of a simple number so you will only be able to create lists of numbers with this code in its current version.

## Use Guide

Download the following files: `List.h`, `Node.h`, `List.cpp`, and `Node.cpp`.

After that in your main file or wherever you want to use lists simply import the `List.h` file like this:

```
#include "List.h"
```

And create an instance of the class like this:

```
List list;
```

Now check the [list of methods](#list_methods) of the `List` to see what type of things you can do.

## List Methods

### `void prepend(int number)`:

Adds an element at the beginning of the list.

Example:

```
List list;

list.prepend(3);
// current list: [3]
list.prepend(5);
// current list: [5, 3]
list.prepend(7);
// current list: [7, 5, 3]
```

### `void append(int number)`:

Adds an element at the end of the list.

Example:

```
List list;

list.append(3);
// current list: [3]
list.append(5);
// current list: [3, 5]
list.append(7);
// current list: [3, 5, 7]
```

### `void remove(int index)`:

Removes an element at a certain index of the list.

### `void removeFirst()`:

Removes the first element of the list.

### `void show()`:

Displays each node of the list in a nice format. Instead of using the show method you could also use cout to print a list:

```
List list;
cout << list;
```

Both will have the same effect, actually using `cout` will call the `show()` method.

### `void clear()`:

Clears the list completely removing each node.

### `int findIndex(int number)`:

Returns the index of the first number that matches the number to search sent as a parameter. If nothing was found it will return `-1`.

Example:

```
List list;

list.append(2);
list.append(3);
list.append(4);
cout << list; // [2, 3, 4]

cout << list.findIndex(3); // returns 1 which is the index of the number 3 in the list

list.append(3);
cout << list; // [2, 3, 4, 3]

cout << list.findIndex(3); // returns 1 since it will always return the index of the first coincidence

cout << list.findIndex(10); // returns -1 since there's no such number in the list
```

### `void insert(int index, int number)`:

Inserts a `number` to the list at the specified `index`
