/* Find Repeat, Space Edition
****Figure out which number is repeated. But here's the catch: optimize for space. 

We have a vector of integers, where:

    1. The integers are in the range 1..n
    2. The vector has a length of n+1

    It follows that our vector has at least one integer which appears at least twice. 
    But it may have several duplicates, and each duplicate may appear more than twice.*/

/* Gotchas
    We can do this in O(1) space.

    We can do this in less than O(n^2) time while keeping O(1) space.

    We can do this in O(nlgn) time and O(1) space.

    We can do this without modifying the input.
    Most O(nlgn) algorithms double something or cut something in half. 
    How can we rule out half of the numbers each time we iterate through the vector?*/

/* Breakdown
    This one's a classic! 
    We just do one walk through the vector, using a set to keep track of which items we've seen!

    unsigned int findRepeat(const vector<unsigned int>& numbers)
    {
        unordered_set<unsigned int> numbersSeen;
        for (unsigned int number : numbers) {
            auto it = numbersSeen.find(number);
            if (it != numbersSeen.end()) {
                return number;
            }
            else {
                numbersSeen.insert(number);
            }
        }

        // whoops--no duplicate
        throw invalid_argument("no duplicate!");
    }

    Bam. O(n) time and ... O(n) space ... 

    We can "brute force" this by taking each number in the range 1..n and, 
    for each, walking through the vector to see if it appears twice.

    unsigned int findRepeat(const vector <unsigned int>& numbers)
    {
        for (unsigned int needle = 1; needle < numbers.size(); ++needle) {
            bool hasBeenSeen = false;
            for (unsigned int number : numbers) {
                if (number == needle) {
                    if (hasBeenSeen) {
                        return number;
                    }
                    else {
                        hasBeenSeen = true;
                    }
                }
            }
        }

        // whoops--no duplicate
        throw invalid_argument("no duplicate!");
    }

    This is O(1) space and O(n^2) time.


    One way to beat O(n^2) time is to getO(nlgn) time. Sorting takes O(nlgn) time. 
    And if we sorted the vector, any duplicates would be right next to each-other!

    But if we start off by sorting our vector we'll need to take O(n)O(n) space to store the sorted vector...

    ...unless we sort the input vector in place! 

    Okay, so this'll work:

        1. Do an in-place sort of the vector (for example an in-place merge sort).
        2. Walk through the now-sorted vector from left to right.
        3. Return as soon as we find two adjacent numbers which are the same.
    This'll keep us at O(1) space and bring us down to O(nlgn) time.

    But modifying the input is kind of a drag—it might cause problems elsewhere in our code. 
    Can we maintain this time and space cost without modifying the input?*/

/* This notion of "we have more items than we have possibilities, so we must have at least one repeat" is pretty powerful. 
    It's sometimes called the pigeonhole principle.

****The pigeonhole principle states that if nitems are put into m containers, with n >m, 
    then at least one container must contain more than one item.

    For example, there must be at least two left gloves or two right gloves in a group of three gloves.

    Can we exploit the pigeonhole principle to see which half of our range contains a repeat?*/

/* Solution
    Our approach is similar to a binary search, except we divide the range of possible answers in half at each step, 
    rather than dividing the vector in half.

    1. Find the number of integers in our input vector which lie within the range 1..(n/2).
    2. Compare that to the number of possible unique integers in the same range.
    3. If the number of actual integers is greater than the number of possible integers, 
       we know there’s a duplicate in the range 1..(n/2), so we iteratively use the same approach on that range.
    4. If the number of actual integers is not greater than the number of possible integers, 
    we know there must be duplicate in the range (n/2 + 1)..n, so we iteratively use the same approach on that range.
    5. At some point, our range will contain just 1 integer, which will be our answer. */

unsigned int findRepeat(const vector<unsigned int>& numbers)
{
    unsigned int floor = 1;
    unsigned int ceiling = numbers.size() - 1;

    while (floor < ceiling) {

        // divide our range 1..n into an upper range and lower range
        // (such that they don't overlap)
        // lower range is floor..midpoint
        // upper range is midpoint+1..ceiling
        unsigned int midpoint = floor + ((ceiling - floor) / 2);
        unsigned int lowerRangeFloor   = floor;
        unsigned int lowerRangeCeiling = midpoint;
        unsigned int upperRangeFloor   = midpoint + 1;
        unsigned int upperRangeCeiling = ceiling;

        // count number of items in lower range
        unsigned int itemsInLowerRange = 0;
        for (unsigned int item : numbers) {
            // is it in the lower range?
            if (item >= lowerRangeFloor && item <= lowerRangeCeiling) {
                ++itemsInLowerRange;
            }
        }

        unsigned int distinctPossibleIntegersInLowerRange = lowerRangeCeiling - lowerRangeFloor + 1;

        if (itemsInLowerRange > distinctPossibleIntegersInLowerRange) {
            // there must be a duplicate in the lower range
            // so use the same approach iteratively on that range
            floor   = lowerRangeFloor;
            ceiling = lowerRangeCeiling;
        }
        else {
            // there must be a duplicate in the upper range
            // so use the same approach iteratively on that range
            floor   = upperRangeFloor;
            ceiling = upperRangeCeiling;
        }
    }

    // floor and ceiling have converged
    // we found a number that repeats!
    return floor;
}

/* Complexity
****O(1) space and O(nlgn) time.

    Tricky as this solution is, we can actually do even better, 
    getting our runtime down to O(n) while keeping our space cost at O(1). 
    The solution is NUTS; it's probably outside the scope of what most interviewers would expect */

/* Bonus
****This function always returns one duplicate, but there may be several duplicates. 
    Write a function that returns all duplicates. */

/* What We Learned
    Our answer was a modified binary search. We got there by reasoning about the expected runtime:

    1. We started with an O(n^2)"brute force" solution and wondered if we could do better.
    2. We knew to beat O(n^2) we'd probably do O(n) or O(nlgn), 
       so we started thinking of ways we might get an O(nlgn) runtime.
    3. lg(n) usually comes from iteratively cutting stuff in half, 
       so we arrived at the final algorithm by exploring that idea.

****Starting with a target runtime and working backward from there 
    can be a powerful strategy for all kinds of coding interview questions. */