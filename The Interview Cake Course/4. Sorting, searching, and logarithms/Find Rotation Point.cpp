/* Breakdown
    The vector is mostly ordered. We should exploit that fact.

    What's a common algorithm that takes advantage of the fact that a vector is sorted to find an item efficiently?

    Binary search! ↴ We can write an adapted version of binary search for this.

    In each iteration of our binary search, ↴ how do we know if the rotation point is to our left or to our right?

    Try drawing out an example vector!

    [ "k","v","a","b","c","d","e","g","i" ]
                    ^

    If our "current guess" is the middle item, 
    which is 'c' in this case, is the rotation point to the left or to the right? How do we know?

    Notice that every item to the right of our rotation point is always alphabetically before the first item in the vector.

***So the rotation point is to our left if the current item is less than the first item. Else it's to our right. */

/* Solution
    This is a modified version of binary search. 
    At each iteration, we go right if the item we're looking at is greater than the first item and we go left if the item we're looking at is less than the first item.

    When floorIndex and ceilingIndex are directly next to each other, 
    we know the floor is the last item we added before starting from the beginning of the dictionary, and the ceiling is the first item we added after.*/

#include <iostream>
#include <string>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

// Time = O(logn), Space = O(1)
size_t findRotationPoint(const vector<string>& words)
{
    size_t floorIndex = 0;
    size_t ceilingIndex = words.size() - 1;

    while (floorIndex < ceilingIndex) {

        // guess a point halfway between floor and ceiling
        size_t guessIndex = floorIndex + ((ceilingIndex - floorIndex) / 2);

        // if guess comes after first word or is the first word
        if (words[guessIndex] >= words[0]) {
            // go right
            floorIndex = guessIndex;
        }
        else {
            // go left
            ceilingIndex = guessIndex;
        }

        // if floor and ceiling have converged
        if (floorIndex + 1 == ceilingIndex) {

            // between floor and ceiling is where we flipped to the beginning
            // so ceiling is alphabetically first
            break;
        }
    }

    return ceilingIndex;
}

// tests

const lest::test tests[] = {
    {CASE("small array") {
        const vector<string> words {"cape", "cake"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 1;
        EXPECT(actual == expected);
    }},
    {CASE("medium array") {
        const vector<string> words {"grape", "orange", "plum", "radish", "apple"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 4;
        EXPECT(actual == expected);
    }},
    {CASE("large array") {
        const vector<string> words {"ptolemaic", "retrograde", "supplant", "undulate",
            "xenoepist", "asymptote", "babka", "banoffee", "engender", "karpatka",
            "othellolagkage"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 5;
        EXPECT(actual == expected);
    }},
    {CASE("possibly missing edge case") {
        // are we missing any edge cases?

    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}

/* Complexity
    Each time we go through the while loop, we cut our range of indices in half, just like binary search. So we have O(lgn) loop iterations.

    In each loop iteration, we do some arithmetic and a string comparison. 
    The arithmetic is constant time, but the string comparison requires looking at characters in both words—every character in the worst case. 
    Here, we'll assume our word lengths are bounded by some constant so we'll say the string comparison takes constant time.

****The longest word in English is pneumonoultramicroscopicsilicovolcanoconiosis, a medical term. It's 45 letters long.

    Putting everything together, we do O(lgn) iterations, and each iteration is O(1) time. So our time complexity is O(lgn).

****Some languages—like German, Russian, and Dutch—can have arbitrarily long words, 
    so we might want to factor the length of the words into our runtime. 
    We could say the length of the words is \ellℓ, each string comparison takes O(ℓ) time, 
    and the whole algorithm takes O(ℓ∗lgn) time.

    We use O(1) space to store the first word and the floor and ceiling indices. */

/* Bonus
    This function assumes that the vector is rotated. If it isn't, what index will it return?
    How can we fix our function to return 0 for an unrotated vector? */

/* What We Learned
    The answer was a modified version of binary search.

    Binary search teaches us that when a vector is sorted or mostly sorted:

    1. The value at a given index tells us a lot about what's to the left and what's to the right.
    2. We don't have to look at every item in the vector. By inspecting the middle item, we can "rule out" half of the vector.
    3. We can use this approach over and over, cutting the problem in half until we have the answer. This is sometimes called "divide and conquer."
       
****So whenever you know a vector is sorted or almost sorted, think about these lessons from binary search and see if they apply. */