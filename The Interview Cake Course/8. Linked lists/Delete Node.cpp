/* Delete a node from a singly-linked list, ↴ given only a variable pointing to that node. */

/* Breakdown
    It might be tempting to try to traverse the list from the beginning until we encounter the node we want to delete. 

    But in this situation, we don't know where the head of the list is—we only have a reference to the node we want to delete.

    But hold on—how do we even delete a node from a linked list in general, when we do have a reference to the first node? 

    So we need a way to skip over the current node and go straight to the next node. But we don't even have access to the previous node!

    Other than rerouting the previous node's pointer, is there another way to skip from the previous pointer's value to the next pointer's value?

****What if we modify the current node instead of deleting it? */

// Solution

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class LinkedListNode {
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int value) :
        intValue_(value),
        next_(nullptr)
    {
    }
};

void deleteNode(LinkedListNode* nodeToDelete)
{
    // get the input node's next node, the one we want to skip to
    LinkedListNode* nextNode = nodeToDelete->next_;

    if (nextNode) {

        // replace the input node's value and pointer with the next
        // node's value and pointer. the previous node now effectively
        // skips over the input node
        nodeToDelete->intValue_ = nextNode->intValue_;
        nodeToDelete->next_  = nextNode->next_;
        delete nextNode;
    }
    else {
        // eep, we're trying to delete the last node!
        throw invalid_argument("Can't delete the last node with this technique!");
    }
}

/* But be careful—there are some potential problems with this implementation:

    First, it doesn't work for deleting the last node in the list.

    Second, this technique can cause some unexpected side-effects */

/*  LinkedListNode a = new LinkedListNode(3);
    LinkedListNode b = new LinkedListNode(8);
    LinkedListNode c = new LinkedListNode(2);

    a.next_ = b;
    b.next_ = c;

    deleteNode(b);

    There are two potential side-effects:

    1. Any references to the input node have now effectively been reassigned to its next_ node. 
    
        In our example, we "deleted" the node assigned to the variable b, but in actuality we just gave it a new value (2) and a new next_! 
        
        If we had another pointer to b somewhere else in our code and we were assuming it still had its old value (8), that could cause bugs.

    2. If there are pointers to the input node's original next node, those pointers now point to a "dangling" node (a node that's no longer reachable by walking down our list). 
    
    In our example above, c is now dangling. If we changed c, we'd never encounter that new value by walking down our list from the head to the tail. */

/* Complexity
    O(1) time and O(1) space. */

/* What We Learned
****My favorite part of this problem is how imperfect the solution is. 

    Because it modifies the list "in place" it can cause other parts of the surrounding system to break. This is called a "side effect."

    In-place operations like this can save time and/or space, but they're risky. 

****If you ever make in-place modifications in an interview, make sure you tell your interviewer that in a real system you'd carefully check for side effects in the rest of the code base. */