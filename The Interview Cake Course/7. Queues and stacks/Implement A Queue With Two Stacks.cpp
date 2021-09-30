/* Implement a queue ↴ with 2 stacks. ↴ Your queue should have an enqueue and a dequeue method and it should be "first in first out" (FIFO).

    Optimize for the time cost of mm calls on your queue. These can be any mix of enqueue and dequeue calls.

    Assume you already have a stack implementation and it gives O(1) time push and pop. */

/* Breakdown 

    So we're basically storing everything in stack1, using stack2 only for temporarily "flipping" all of our items during a dequeue to get the bottom (oldest) element.

    This is a complete solution. But we can do better. 

    What's our time complexity for m operations? 

    At any given point we have O(m) items inside our data structure, and if we dequeue we have to move all of them from stack1 to stack2 and back again. 
    One dequeue operation thus costs O(m). The number of dequeues is O(m), so our worst-case runtime for these m operations is O(m^2)

    We can do better than this O(m^2) runtime.

****What if we didn't move things back to stack1 after putting them on stack2?*/

// Solution
#include <iostream>
#include <stack>

using namespace std;

class QueueTwoStacks
{
private:
    stack<int> inStack_;
    stack<int> outStack_;

public:
    void enqueue(int item)
    {
        inStack_.push(item);
    }

    int dequeue()
    {
        if (outStack_.empty()) {
            // Move items from inStack to outStack, reversing order
            while (!inStack_.empty()) {
                int newestInStackItem = inStack_.top();
                inStack_.pop();
                outStack_.push(newestInStackItem);
            }

            // If outStack is still empty, raise an error
            if (outStack_.empty()) {
                throw runtime_error("Can't dequeue from empty queue!");
            }
        }

        int result = outStack_.top();
        outStack_.pop();
        return result;
    }
};

/* Complexity
    Each enqueue is clearly O(1) time, and so is each dequeue when outStack_ has items. 

    Dequeue on an empty outStack_ is order of the number of items in inStack_ at that moment, which can vary significantly.

    Notice that the more expensive a dequeue on an empty outStack_ is (that is, the more items we have to move from inStack_ to outStack_), 

    the more O(1)-time dequeues off of a non-empty outStack_ it wins us in the future. 

    Once items are moved from inStack_ to outStack_ they just sit there, ready to be dequeued in O(1) time. 

    An item never moves "backwards" in our data structure.

    We might guess that this "averages out" so that in a set of mm enqueues and dequeues the total cost of all dequeues is actually just O(m). 

****To check this rigorously, we can use the accounting method, ↴ counting the time cost per item instead of per enqueue or dequeue.

    So let's look at the worst case for a single item, which is the case where it is enqueued and then later dequeued. 
    In this case, the item enters inStack_ (costing 1 push), then later moves to outStack_ (costing 1 pop and 1 push), then later comes off outStack_ to get returned (costing 1 pop).

    Each of these 4 pushes and pops is O(1) time. So our total cost per item is O(1). 

    Our m enqueue and dequeue operations put m or fewer items into the system, giving a total runtime of O(m).*/

/* What We Learned
    People often struggle with the runtime analysis for this one. 

****The trick is to think of the cost per item passing through our queue, rather than the cost per enqueue() and dequeue().

****This trick generally comes in handy when you're looking at the time cost of not just one call, but "m" calls. */