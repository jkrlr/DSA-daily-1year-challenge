/* Use the built-in stack class to implement a new class MaxStack with a method getMax() that returns the largest element in the stack. 
   getMax() should not remove the item.

Your stacks will contain only integers. */

/* Breakdown
    A just-in-time ↴ approach is to have getMax() simply walk through the stack (popping all the elements off and then pushing them back on) to find the max element. 

    This takes O(n) time for each call to getMax(). But we can do better. 

    To get O(1) time for getMax(), we could store the max integer as a member variable (call it max). 

    But how would we keep it up to date?

    For every push(), we can check to see if the item being pushed is larger than the current max, assigning it as our new max if so. 

    But what happens when we pop() the current max?

    What if when we find a new current max (newMax), instead of overwriting the old one (oldMax) we held onto it, 

    so that once newMax was popped off our stack we would know that our max was back to oldMax?

    What data structure should we store our set of maxes in? 

    We want something where the last item we put in is the first item we get out ("last in, first out").

    We can store our maxes in another stack!

*/

#include <iostream>
#include <stack>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class MaxStack
{
private:
    stack<int> stack_;
    stack<int> maxesStack_;

public:
    // Add a new item to the top of our stack. If the item is greater
    // than or equal to the last item in maxesStack, it's
    // the new max! So we'll add it to maxesStack.
    void push(int item)
    {
        stack_.push(item);
        if (maxesStack_.empty() || item >= maxesStack_.top()) {
            maxesStack_.push(item);
        }
    }

    // Remove and return the top item from our stack. If it equals
    // the top item in maxesStack, they must have been pushed in together.
    // So we'll pop it out of maxesStack too.
    int pop()
    {
        int item = stack_.top();
        stack_.pop();
        if (item == maxesStack_.top()) {
            maxesStack_.pop();
        }
        return item;
    }

    // The last item in maxesStack is the max item in our stack.
    int getMax() const
    {
        return maxesStack_.top();
    }
};

// tests

const lest::test tests[] = {
    {CASE("MaxStack test") {
        MaxStack s;
        s.push(5);
        EXPECT(s.getMax() == 5);
        s.push(4);
        s.push(7);
        s.push(7);
        s.push(8);
        EXPECT(s.getMax() == 8);
        EXPECT(s.pop() == 8);
        EXPECT(s.getMax() == 7);
        EXPECT(s.pop() == 7);
        EXPECT(s.getMax() == 7);
        EXPECT(s.pop() == 7);
        EXPECT(s.getMax() == 5);
        EXPECT(s.pop() == 4);
        EXPECT(s.getMax() == 5);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}

/* Complexity
    O(1) time for push(), pop(), and getMax(). 
    O(m) additional space, where m is the number of operations performed on the stack. */

/* Bonus
    Our solution requires O(m) additional space for the second stack. But do we really need it?

    Can you come up with a solution that requires O(1) additional space? (It's tricky!) */

/* What We Learned
    Notice how in the solution we're spending time on push() and pop() so we can save time on getMax(). 
    
    That's because we chose to optimize for the time cost of calls to getMax().

    But we could've chosen to optimize for something else. 
    
    For example, if we expected we'd be running push() and pop() frequently and running getMax() rarely, we could have optimized for faster push() and pop() methods.

    Sometimes the first step in algorithm design is deciding what we're optimizing for. 
    
    Start by considering the expected characteristics of the input. */