//This is the implementation file queue.cpp.
 //This is the implementation of the class Queue.
 //The interface for the class Queue is in the header file queue.h.
 #include <iostream>
 #include <cstdlib>
 #include <cstddef>
 #include "Queue.h"
 using namespace std;

 namespace queuesavitch
 {
     //Uses cstddef:
         Queue::Queue() : front(NULL), back(NULL)
         {
         //Intentionally empty.
             }
    
         Queue::Queue(const Queue& aQueue) {
             if (aQueue.empty()) {
                 front = back = NULL;
             }

             else {
                 QueueNodePtr tempPtrOld = aQueue.front;
                 QueueNodePtr tempPtrNew;
                 back = new QueueNode;
                 back->data = tempPtrOld->data;
                 back->link = NULL;
                 front = back;
                 tempPtrOld = tempPtrOld->link;
                 while (tempPtrOld != NULL) {
                     tempPtrNew = new QueueNode;
                     tempPtrNew->data = tempPtrOld->data;
                     tempPtrNew->link = NULL;
                     back->link = tempPtrNew;
                     back = tempPtrNew;
                     tempPtrOld = tempPtrOld->link;
                 }
             }
         }

         Queue::~Queue() {
             char next;
             while (!empty()) {
                 next = remove();//remove calls delete.
             }
         }
        
         //Uses cstddef:
         bool Queue::empty() const
         {
         return (back == NULL); //front == NULL would also work
         }
    
         //Uses cstddef:
         void Queue::add(char item)
         {
         if (empty())
             {
             front = new QueueNode;
             front->data = item;
             front->link = NULL;
             back = front;
             }
        
             else
             {
             QueueNodePtr tempPtr;
             tempPtr = new QueueNode;
             tempPtr->data = item;
             tempPtr->link = NULL;
             back->link = tempPtr;
             back = tempPtr;
             }
         }
    
         //Uses cstdlib and iostream:
         char Queue::remove()
         {
         if (empty())
             {
             cout << "Error: Removing an item from an empty queue.\n";
             exit(1);
             }
        
             char result = front->data;
      
             QueueNodePtr discard;
         discard = front;
         front = front->link;