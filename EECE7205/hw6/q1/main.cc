#include <iostream>
#include "HashTable.h"
#include "Person.h"
#include "String.h"
#include <cstdlib>
#include <vector>

int main() {

// Create hash table
    HashTable table;
// Create persons
    Person p1("John", "Smith", 20, "jsmith@neu.edu");
    Person p2("Adam", "Taylor", 25, "ataylor@neu.edu");
    Person p3("Tracy", "Terry", 30, "tterry@neu.edu");
    Person p4("Julie", "Tillman", 35, "jtillman@neu.edu");
    Person p5("Michael", "Mace", 40, "mmace@neu.edu");
    Person p6("Florence", "Tarrance", 45, "ftarrance@neu.edu");
    Person p7("Steven", "Cole", 50, "scole@neu.edu");
// Insert persons
    table.Insert(&p1.last, &p1);
    table.Insert(&p2.last, &p2);
    table.Insert(&p3.last, &p3);
    table.Insert(&p4.last, &p4);
    table.Insert(&p5.last, &p5);
    table.Insert(&p6.last, &p6);
    table.Insert(&p7.last, &p7);
// Print all elements
    //std::cout << '\n' << std::string(40, '=') << '\n';
    //std::cout << "Listing table...\n";
   // table.Print();
    //case1 normal
    std::cout<<"\ncase 1 normal element of Smith\n";
    String *succ1 = (String *) table.Succ(&p1.last);
    if (succ1 != NULL)
    {
        std::cout<<"the successor is ";
        succ1->Print();
    } else {
        std::cout<<"\nNO SUCCESSOR\n";
    }
    //case2 unk element
    std::cout<<"\ncase 2 unk element\n";
    String unk("Yaqiao");
    String *succ2 = (String *) table.Succ(&unk);
    if (succ2 != NULL)
    {
        succ2->Print();
    } else {
        std::cout<<"\nNO SUCCESSOR\n";
    }
    //case3 last element
    std::cout<<"\ncase 3 last element\n";
    String *succ3 = (String *) table.Succ(&p4.last);
    if (succ3 != NULL)
    {
        succ3->Print();
    } else {
        std::cout<<"\nNO SUCCESSOR\n";
    }


    /* correct order
    Cole
    Mace
    Smith
    Tarrance
    Taylor
    Terry
    Tillman
    */
    return 0;
}
