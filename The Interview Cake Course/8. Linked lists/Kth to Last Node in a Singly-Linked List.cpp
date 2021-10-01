/* You have a linked list ↴ and want to find the kkth to last node. */

/* Breakdown
    It might be tempting to iterate through the list until we reach the end and then walk backward k nodes.

    But we have a singly linked list! We can’t go backward. What else can we do? 

    What if we had the length of the list?

    Well, we don't know the length of the list (nn). But can we figure it out?

    Yes, we could iterate from the head to the tail and count the nodes!

    Can we do better?

    The fact that we walk through our whole list once just to get the length, 

    then walk through the list again to get to the kth to last element sounds like a lot of work. 

    Perhaps we can do this in just one pass?
    
    maintain a k-wide "stick" in one walk down the list.
    
    How can we implement this? Maybe it'll help to keep two pointers?

    This'll work, but does it actually save us any time? */

// Solution 

#include <iostream>
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

// 1st approach
LinkedListNode * kthToLastNode(size_t k, LinkedListNode* head)
{
    if (k < 1) {
        throw invalid_argument(
                "Impossible to find less than first to last node: "
                + to_string(k));
    }

    // STEP 1: get the length of the list
    // start at 1, not 0
    // else we'd fail to count the head node!
    size_t listLength = 1;
    LinkedListNode* currentNode = head;

    // traverse the whole list,
    // counting all the nodes
    while (currentNode->next_) {
        currentNode = currentNode->next_;
        ++listLength;
    }

    // if k is greater than the length of the list, there can't
    // be a kth-to-last node, so we'll return an error!
    if (k > listLength) {
        throw invalid_argument(
                "k is larger than the length of the linked list: "
                + to_string(k));
    }

    // STEP 2: walk to the target node
    // calculate how far to go, from the head,
    // to get to the kth to last node
    size_t howFarToGo = listLength - k;

    currentNode = head;
    for (size_t i = 0; i < howFarToGo; ++i) {
        currentNode = currentNode->next_;
    }

    return currentNode;
}

// 2nd approach

LinkedListNode * kthToLastNode(size_t k, LinkedListNode* head)
{

    if (k < 1) {
        throw invalid_argument(
                "Impossible to find less than first to last node: "
                + to_string(k));
    }

    LinkedListNode* leftNode  = head;
    LinkedListNode* rightNode = head;

    // move rightNode to the kth node
    for (size_t i = 0; i < k - 1; ++i) {

        // but along the way, if a rightNode doesn't have a next,
        // then k is greater than the length of the list and there
        // can't be a kth-to-last node! we'll raise an error
        if (!rightNode->next_) {
            throw invalid_argument(
                    "k is larger than the length of the linked list: "
                    + to_string(k));
        }

        rightNode = rightNode->next_;
    }

    // starting with leftNode on the head,
    // move leftNode and rightNode down the list,
    // maintaining a distance of k between them,
    // until rightNode hits the end of the list
    while (rightNode->next_) {
        leftNode  = leftNode->next_;
        rightNode = rightNode->next_;
    }

    // since leftNode is k nodes behind rightNode,
    // leftNode is now the kth to last node!
    return leftNode;
}

/* Complexity
    Both approaches use O(n) time and O(1) space.

****But the second approach is fewer steps since it gets the answer "in one pass," right? Wrong.

    In the first approach, we walk one pointer from head to tail (to get the list's length), then walk another pointer from the head node to the target node (the kth to last node).

    In the second approach, rightNode also walks all the way from head to tail, and leftNode also walks from the head to the target node.

****So in both cases, we have two pointers taking the same steps through our list. 

    The only difference is the order in which the steps are taken. 

    The number of steps is the same either way.

****However, the second approach might still be slightly faster, due to some caching and other optimizations that modern processors and memory have.

    Let's focus on caching. Usually when we grab some data from memory (for example, info about a linked list node), we also store that data in a small cache right on the processor. 
    
    If we need to use that same data again soon after, we can quickly grab it from the cache. 
    
    But if we don't use that data for a while, we're likely to replace it with other stuff we've used more recently (this is called a "least recently used" replacement policy).

****Both of our algorithms access a lot of nodes in our list twice, so they could exploit this caching. 

    But notice that in our second algorithm there's a much shorter time between the first and second times that we access a given node (this is sometimes called "temporal locality of reference"). 
    
    Thus it seems more likely that our second algorithm will save time by using the processor's cache! 
    
    But this assumes our processor's cache uses something like a "least recently used" replacement policy—it might use something else. 
    
****Ultimately the best way to really know which algorithm is faster is to implement both and time them on a few different inputs! */

/* Bonus
    Can we do better? What if we expect n to be huge and k to be pretty small? 
    
      In this case, our target node will be close to the end of the list...so it seems a waste that we have to walk all the way from the beginning twice.

    Can we trim down the number of steps in the "second trip"? 
     
     One pointer will certainly have to travel all the way from head to tail in the list to get the total length...
     
     but can we store some "checkpoints" as we go so that the second pointer doesn't have to start all the way at the beginning? 
     
     Can we store these "checkpoints" in constant space? 
     
     Note: this approach only saves time if we know that our target node is towards the end of the list (in other words, n is much larger than k). */

/* What We Learned
    We listed two good solutions. One seemed to solve the problem in one pass, while the other took two passes. 
    
    But the single-pass approach didn't take half as many steps, it just took the same steps in a different order.

****So don't be fooled: "one pass" isn't always fewer steps than "two passes." 

****Always ask yourself, "Have I actually changed the number of steps?" */