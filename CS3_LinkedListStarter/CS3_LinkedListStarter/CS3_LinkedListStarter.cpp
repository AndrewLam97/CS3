/*
    CS3
    Linked List Starter
*/
#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList ll;
    LinkedList ll2;

    ll.insertAfter(1); //1
    ll.insertAfter(2); //1 2
    ll.insertBefore(3); //3 1 2
    ll.insertAfter(4); //3 1 2 4
    ll.insertBefore(5); // 5 3 1 2 4
    ll += 6; // 5 3 1 2 4 6

    ll2.insertBefore(500); //500
    ll2.insertAfter(200); //500 200
    ll2.insertBefore(123); //123 500 200
    
    ll += ll2; //5 3 1 2 4 6 123 500 200

    ll.insertBefore(7); //7 5 3 1 2 4 6 123 500 200

    ll += 99; //7 5 3 1 2 4 6 123 500 200 99

    ll.print();
    std::cout << std::endl << ll; //Expected: 7 5 3 1 2 4 6 123 500 200 99
}
