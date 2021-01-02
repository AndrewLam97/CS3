#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "Queue.h"
using namespace std;
using namespace queuesavitch;

int main()
{
    Queue::Queue(const Queue & aQueue) {
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
}

/*
    1. Sally
       Sally
       18
       18
    2. head->next = nullptr
    3. delete head
    4. head->item = "Wilbur's brother Orville";
    5. struct NodeType {
        char data;
        Node * link;
       };

       typedef NodeType * PointerType
    6. NULL indicates that the ll is empty
    7. p1 = p1->next;
    8. Pointer discard;
       discard = p2->next;
       p2->next = discard->next;
       delete discard;
    9. More efficient because pointer reassignment is faster than shifting post elements's memory addresses in an array
    10. void Stack::push(char theSymbol){
            StackFramePtr tempPtr;
            tempPtr = new StackFrame;
            tempPtr->link = top;
            tempPtr->data = theSymbol;

            top = tempPtr;
        }
    11. Stack::Stack(const Stack& aStack) {
            if (aStack.top == NULL) {
                top = NULL;
            }
            else {
                StackFramePtr temp = aStack.top;
                StackFramePtr end;
                end = new StackFrame;
                end->data = temp->data;
                top = end;
                temp = temp->link;
                while (temp != NULL) {
                    end->link = new StackFrame;
                    end = end->link;
                    end->data = temp->data;
                    temp = temp->link;
                }
                end->link = NULL;
            }
        }
    12. Queue::Queue(const Queue&aQueue) {
            if (aQueue.empty( )) {
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
    13. Queue::~Queue( ) {
            char next;
            while (!empty()) {
                next = remove();//remove calls delete.
            }
        }
*/