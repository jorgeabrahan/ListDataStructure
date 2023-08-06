# ListDataStructure

## Use Guide

Download the following files: `List.h`, `Node.h`, `List.cpp` and `Node.cpp`.

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

`void prepend(int number)`:
Adds an element at the beginning of the list.
Example:
`list.prepend(3);`
current list: [3]
`list.prepend(5);`
current list: [5, 3]
`list.prepend(7);`
current list: [7, 5, 3]

`void append(int number)`:
Adds an element at the end of the list.
Example:
`list.append(3);`
current list: [3]
`list.append(5);`
current list: [3, 5]
`list.append(7);`
current list: [3, 5, 7]

`void remove(int index)`:
Removes an element at a certain index of the list.

`void removeFirst()`
`void show()`
`void clear()`
`int findIndex(int number)`
`void insert(int index, int number)`
