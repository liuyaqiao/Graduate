#include <iostream>
#include <cstdlib>
#include "Hashtable.h"
#include "Person.h"
#include "String.h"

int main() {
    Hashtable table(5);
// Create persons
    Person p1("John", "Smith", 20, "jsmith@neu.edu");
    Person p2("Adam", "Taylor", 25, "ataylor@neu.edu");
    Person p3("Tracy", "Terry", 30, "tterry@neu.edu");
    Person p4("Julie", "Tillman", 35, "jtillman@neu.edu");
    Person p5("Michael", "Mace", 40, "mmace@neu.edu");
    Person p6("Florence", "Tarrance", 45, "ftarrance@neu.edu");
    Person p7("Steven", "Cole", 50, "scole@neu.edu");
    Person p8("Yaqiao", "Liu", 25, "liu.yaqi@husky.neu.edu");
// Insert persons
    table.Insert(&p1.last, &p1.first);
    table.Insert(&p2.last, &p2.first);
    table.Insert(&p3.last, &p3.first);
    table.Insert(&p4.last, &p4.first);
    table.Insert(&p5.last, &p5.first);
    table.Insert(&p6.last, &p6.first);
    table.Insert(&p7.last, &p7.first);


    std::cout<<"\n-------Test---------------------------\n";
    std::cout<<"\n-------the original table------------------\n";
    table.Print();

    std::cout<<"\n-------Search----------------\n";

    if (table.Search(&p7.last)) {
        table.Search(&p7.last)->Print();
    } else {
        std::cout<<"\nNot Found\n";
    }

    if (table.Search(&p3.last)) {
        table.Search(&p3.last)->Print();
    } else {
        std::cout<<"\nNot Found\n";
    }

    std::cout<<"\n-------Delete----------------\n";

    table.Delete(&p1.last);
    table.Print();

    std::cout<<"\n-----------------------\n";

    return 0;
}