// Find a duplicate, Space Edition™ BEAST MODE

/* In Find a duplicate, Space Edition™, we were given a vector of integers where:

    the integers are in the range 1..n
    the vector has a length of n+1
    These properties mean the vector must have at least 1 duplicate 
    
    But we can actually do better(Earlier we did it in O(logN) time and O(1) Space).
    We can find a duplicate integer in O(n) time while keeping our space cost at O(1)*/

/* Breakdown
    Here are a few sample vectors. Try drawing them out as linked lists:

    [3, 4, 2, 3, 1, 5]
    [3, 1, 2, 2]
    [4, 3, 1, 1, 4]

    Look for patterns. Then think about how we might use those patterns to find a duplicate number in our vector.

    When a value is repeated, how will that affect the structure of our linked list?

    If two nodes have the same value, their next pointers will point to the same node!
    
    So if we can find a node with two incoming next pointers, we know the position of that node is a duplicate integer in our vector.

    How can we find a node with multiple incoming pointers?
    
    Are there any patterns in linked list of vectors that might help us find a node with two incoming pointers?

    Here’s a pattern: the last node never has any incoming pointers.
    This makes sense—since the vector has a length n+1 and all the values are n or less, there can never be a pointer to the last position.
    
    Since it has no incoming pointers, we should treat the last position in our vector as the "head" (starting point) of our linked list.

    Here's another pattern: there’s never an end to our list. No pointer ever points to nullptr.
    
    Every node has a value in the range 1..n, so every node points to another node (or to itself). 
    Since the list goes on forever, it must have a cycle (a loop). 
    
    Can we use these cycles to find a duplicate value?

    The first node in the cycle always has at least two incoming pointers!

    How can we find the beginning of a cycle?
    
    What if we knew the length of the cycle?

    How can we find the length of a cycle?
    
    
    If we can get inside the cycle, we can just remember a position and count how many steps it takes to get back to that position.

    How can we make sure we’ve gotten inside a cycle?
    
    Well, there has to be a cycle in our list, and at the latest, the cycle is just the last node we hit as we traverse the list from the head:

    We can just start at the head and walk n steps. By then we'll have to be inside a cycle.*/

/* We want to think of our vector as a linked list but we don't want to actually use up all that space, 
   so we traverse our vector as if it were a linked list ↴ by converting positions to indices. */

#include <iostream>
#include <vector>

using namespace std;

unsigned int findDuplicate(const vector<unsigned int>& intVector)
{
    const unsigned int n = static_cast<unsigned int>(intVector.size() - 1);

    // STEP 1: GET INSIDE A CYCLE
    // start at position n+1 and walk n steps to
    // find a position guaranteed to be in a cycle
    unsigned int positionInCycle = n + 1;
    for (unsigned int i = 0; i < n; ++i) {

        // we subtract 1 from the current position to step ahead:
        // the 2nd *position* in an array is *index* 1
        positionInCycle = intVector[positionInCycle - 1];
    }

    // STEP 2: FIND THE LENGTH OF THE CYCLE
    // find the length of the cycle by remembering a position in the cycle
    // and counting the steps it takes to get back to that position
    unsigned int rememberedPositionInCycle = positionInCycle;
    unsigned int currentPositionInCycle = intVector[positionInCycle - 1];  // 1 step ahead
    unsigned int cycleStepCount = 1;

    while (currentPositionInCycle != rememberedPositionInCycle) {
        currentPositionInCycle = intVector[currentPositionInCycle - 1];
        ++cycleStepCount;
    }

    // STEP 3: FIND THE FIRST NODE OF THE CYCLE
    // start two pointers
    //   (1) at position n+1
    //   (2) ahead of position n+1 as many steps as the cycle's length
    unsigned int pointerStart = n + 1;
    unsigned int pointerAhead = n + 1;
    for (size_t i = 0; i < cycleStepCount; ++i) {
        pointerAhead = intVector[pointerAhead - 1];
    }

    // advance until the pointers are in the same position
    // which is the first node in the cycle
    while (pointerStart != pointerAhead) {
        pointerStart = intVector[pointerStart - 1];
        pointerAhead = intVector[pointerAhead - 1];
    }

    // since there are multiple values pointing to the first node
    // in the cycle, its position is a duplicate in our array
    return pointerStart;
}

/* Complexity
    O(n) time and O(1) space. */

/* Bonus
    There another approach using randomized algorithms that is O(n) time and O(1) space. 
    Can you come up with that one? (Hint: You'll want to focus on the median.) */

/* What We Learned
    This one's pretty crazy. It's hard to imagine an interviewer expecting you to get all the way through this question without help.

    But just because it takes a few hints to get to the answer doesn't mean a question is "too hard." 
    Some interviewers expect they'll have to offer a few hints.

****So if you get a hint in an interview, just relax and listen. 
****The most impressive thing you can do is drop what you're doing, fully understand the hint, and then run with it. */