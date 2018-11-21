#include <iostream>
#include <cstdlib>
#include "Tree.h"
#include "Integer.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Tree tree;

// Insert persons
    tree.Insert(new Integer(4),new Integer(4) );
    tree.Insert(new Integer(2),new Integer(2) );
    tree.Insert(new Integer(8),new Integer(8) );
    tree.Insert(new Integer(3),new Integer(3) );
    tree.Insert(new Integer(5),new Integer(5) );
    tree.Insert(new Integer(6),new Integer(6) );
    tree.Insert(new Integer(7),new Integer(7) );
    tree.getHeight();
//     Print all elements

    std::cout << "Listing tree...\n";
    tree.Print();

    return 0;
}
