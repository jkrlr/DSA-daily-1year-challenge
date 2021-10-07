/* Given the vector of IDs, which contains many duplicate integers and one unique integer, find the unique integer.

    The IDs are not guaranteed to be sorted or sequential. 
    Orders aren't always fulfilled in the order they were received, and some deliveries get cancelled before takeoff. */

/* Breakdown
    A brute force approach would use two nested loops to go through every ID and check every other ID to see if there's a duplicate.

    This would take O(n^2) time and O(1) space. Can we bring that runtime down? 

    Well, we know every integer appears twice, except for one integer, which appears once. 

    Can we just track how many times each integer appears?

    We could iterate through the vector and store each integer in an unordered map.

    Alright, we got our runtime down to O(n). 

    That's probably the best runtime we can get—to find our unique integer we’ll definitely have to look at every integer in the worst case.

    But now we've added O(n) space, for our unordered map. Can we bring that down?

    Well, we could use booleans.

    Even if each boolean were just 1 bit, that'd still be O(n) space overall.

    So using booleans probably doesn't save us much space here. Any other ideas?

    Let’s zoom out and think about what we’re working with. The only data we have is integers. How are integers stored?

    Our machine stores integers as binary numbers using bits. 

    What if we thought about this problem on the level of individual bits?

    Let's think about the bitwise operations AND, OR, XOR, NOT and bit shifts. 

    Is one of those operations helpful for finding our unique integer?

    We’re seeing every integer twice, except one. 

    Is there a bitwise operation that would let the second occurrence of an integer cancel out the first?

    Which bitwise operation would let us do that?

    XOR */

// Solution

int findUniqueDeliveryId(const vector<int>& deliveryIds)
{
    int uniqueDeliveryId = 0;

    for (int deliveryId : deliveryIds) {
        uniqueDeliveryId ^= deliveryId;
    }

    return uniqueDeliveryId;
}

/* Complexity
    O(n) time, and O(1) space.*/

/* What We Learned
    This problem is a useful reminder of the power we can unlock by knowing what's happening at the "bit level." 

****How do you know when bit manipulation might be the key to solving a problem? 

    Here are some signs to watch out for:

****1. You want to multiply or divide by 2 (use a left shift to multiply by 2, right shift to divide by 2).

****2. You want to "cancel out" matching numbers (use XOR).*/